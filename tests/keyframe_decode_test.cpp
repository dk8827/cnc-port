#include "crc.h"
#include "memflag.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <string>
#include <vector>

unsigned long Build_Frame(void const *dataptr, unsigned short framenumber, void *buffptr);
unsigned short Get_Build_Frame_Count(void const *dataptr);
unsigned short Get_Build_Frame_Width(void const *dataptr);
unsigned short Get_Build_Frame_Height(void const *dataptr);
void *Get_Shape_Header_Data(void *ptr);
extern int UseBigShapeBuffer;

void (*Memory_Error)(void) = 0;
void (*Memory_Error_Exit)(char *) = 0;

void Memory_Error_Handler(void)
{
}

void *Alloc(unsigned long bytes, MemoryFlagType)
{
	return malloc((size_t)bytes);
}

void *Resize_Alloc(void *pointer, unsigned long bytes)
{
	return realloc(pointer, (size_t)bytes);
}

extern "C" void Mem_Copy(void const *source, void *dest, unsigned long bytes)
{
	memmove(dest, source, (size_t)bytes);
}

extern "C" unsigned int Apply_XOR_Delta(char *target, char *delta)
{
	unsigned char *out = (unsigned char *)target;
	unsigned char const *source = (unsigned char const *)delta;
	unsigned int total = 0;
	for (;;) {
		unsigned int opcode = *source++;
		if (opcode > 0 && opcode < 0x80) {
			total += opcode;
			while (opcode--) *out++ ^= *source++;
			continue;
		}
		if (opcode == 0) {
			unsigned int count = *source++;
			unsigned char value = *source++;
			total += count;
			while (count--) *out++ ^= value;
			continue;
		}

		opcode -= 0x80;
		if (opcode != 0) {
			total += opcode;
			out += opcode;
			continue;
		}

		unsigned int count = (unsigned int)source[0] | ((unsigned int)source[1] << 8);
		source += 2;
		if (count == 0) break;
		if ((count & 0x8000) == 0) {
			total += count;
			out += count;
			continue;
		}
		count -= 0x8000;
		total += count & ~0x4000;
		if (count & 0x4000) {
			count -= 0x4000;
			unsigned char value = *source++;
			while (count--) *out++ ^= value;
		} else {
			while (count--) *out++ ^= *source++;
		}
	}
	return total;
}

static unsigned int read_u16(unsigned char const *data)
{
	return (unsigned int)data[0] | ((unsigned int)data[1] << 8);
}

static uint32_t read_u32(unsigned char const *data)
{
	return (uint32_t)data[0] |
		((uint32_t)data[1] << 8) |
		((uint32_t)data[2] << 16) |
		((uint32_t)data[3] << 24);
}

static bool read_file(char const *path, std::vector<unsigned char> &data)
{
	std::ifstream file(path, std::ios::binary | std::ios::ate);
	if (!file) return false;
	std::streamoff size = file.tellg();
	if (size <= 0) return false;
	data.resize((size_t)size);
	file.seekg(0);
	file.read((char *)&data[0], size);
	return file.good();
}

static bool extract_mix_file(std::vector<unsigned char> const &mix, char const *name, std::vector<unsigned char> &data)
{
	if (mix.size() < 6) return false;
	unsigned int count = read_u16(&mix[0]);
	size_t data_start = 6 + (size_t)count * 12;
	if (data_start > mix.size()) return false;

	std::string upper(name);
	for (size_t i = 0; i < upper.size(); ++i) {
		if (upper[i] >= 'a' && upper[i] <= 'z') upper[i] -= 'a' - 'A';
	}
	int32_t wanted_crc = (int32_t)CRCEngine()(&upper[0], (int)upper.size());

	for (unsigned int i = 0; i < count; ++i) {
		unsigned char const *entry = &mix[6 + (size_t)i * 12];
		if ((int32_t)read_u32(entry) != wanted_crc) continue;
		size_t offset = data_start + read_u32(entry + 4);
		size_t size = read_u32(entry + 8);
		if (offset > mix.size() || size > mix.size() - offset) return false;
		data.assign(mix.begin() + offset, mix.begin() + offset + size);
		return true;
	}
	return false;
}

static int check_shape(std::vector<unsigned char> &shape, char const *name)
{
	unsigned int width = Get_Build_Frame_Width(&shape[0]);
	unsigned int height = Get_Build_Frame_Height(&shape[0]);
	unsigned int frames = Get_Build_Frame_Count(&shape[0]);
	if (width == 0 || height == 0 || frames < 32) {
		fprintf(stderr, "FAIL: %s has invalid dimensions/frame count (%ux%u, %u frames)\n", name, width, height, frames);
		return 1;
	}

	std::vector<unsigned char> pixels(width * height, 0xcd);
	unsigned int directional_frames = frames < 64 ? frames : 64;
	for (unsigned int index = 0; index < directional_frames; ++index) {
		unsigned int bank = index / 32;
		unsigned int facing = index % 32;
		unsigned int frame = bank * 32 + (facing == 0 ? 0 : 32 - facing);
		if (frame >= directional_frames) frame = index;
		memset(&pixels[0], 0xcd, pixels.size());
		unsigned long result = Build_Frame(&shape[0], (unsigned short)frame, &pixels[0]);
		if (result == 0) {
			fprintf(stderr, "FAIL: %s frame %u could not be decoded\n", name, frame);
			return 1;
		}
		unsigned char const *rendered = (unsigned char const *)Get_Shape_Header_Data((void *)result);
		size_t visible = 0;
		size_t solid = 0;
		for (size_t i = 0; i < pixels.size(); ++i) {
			if (rendered[i] != 0) {
				++visible;
				if (rendered[i] != 4) ++solid; /* LTGREEN is the unit-shadow control color. */
			}
		}
		if (visible == 0) {
			fprintf(stderr, "FAIL: %s frame %u is fully transparent\n", name, frame);
			return 1;
		}
		if (solid == 0) {
			fprintf(stderr, "FAIL: %s frame %u contains only shadow pixels\n", name, frame);
			return 1;
		}
	}

	printf("PASS: %s %ux%u, %u/%u directional frames visible\n", name, width, height, directional_frames, frames);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s CONQUER.MIX\n", argv[0]);
		return 2;
	}

	std::vector<unsigned char> mix;
	if (!read_file(argv[1], mix)) {
		fprintf(stderr, "FAIL: cannot read %s\n", argv[1]);
		return 1;
	}
	UseBigShapeBuffer = 1;

	char const *names[] = {
		"JEEP.SHP", "BGGY.SHP", "APC.SHP", "LTNK.SHP", "MTNK.SHP", "HTNK.SHP",
		"MLRS.SHP", "MSAM.SHP", "ARTY.SHP", "HARV.SHP", "MCV.SHP", "FTNK.SHP", "STNK.SHP"
	};
	for (size_t i = 0; i < sizeof(names) / sizeof(names[0]); ++i) {
		std::vector<unsigned char> shape;
		if (!extract_mix_file(mix, names[i], shape)) {
			fprintf(stderr, "FAIL: %s not found in MIX\n", names[i]);
			return 1;
		}
		if (check_shape(shape, names[i])) return 1;
	}
	return 0;
}
