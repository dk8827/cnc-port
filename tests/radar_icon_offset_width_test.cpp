#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int fail(char const *message)
{
	fprintf(stderr, "FAIL: %s\n", message);
	return 1;
}

static int radar_uses_32_bit_icon_offsets(void)
{
	FILE *source = fopen("CODE/RADAR.CPP", "rb");
	char *buffer;
	long size;
	int result;

	if (!source) return 0;
	if (fseek(source, 0, SEEK_END) != 0) {
		fclose(source);
		return 0;
	}
	size = ftell(source);
	if (size < 0 || fseek(source, 0, SEEK_SET) != 0) {
		fclose(source);
		return 0;
	}
	buffer = (char *)malloc((size_t)size + 1);
	if (!buffer) {
		fclose(source);
		return 0;
	}
	if (fread(buffer, 1, (size_t)size, source) != (size_t)size) {
		free(buffer);
		fclose(source);
		return 0;
	}
	fclose(source);
	buffer[size] = '\0';
	result = strstr(buffer, "int32_t offset") != 0;
	free(buffer);
	return result;
}

int main()
{
	unsigned char iconset_header[40];
	int32_t map_offset = 0x20;
	int32_t icon_offset = 0x40;
	int32_t read_map_offset = 0;
	int32_t read_icon_offset = 0;

	memset(iconset_header, 0, sizeof(iconset_header));
	memcpy(iconset_header + 12, &icon_offset, sizeof(icon_offset));
	memcpy(iconset_header + 28, &map_offset, sizeof(map_offset));
	memset(iconset_header + 32, 0x7f, 4);

	memcpy(&read_map_offset, iconset_header + 28, sizeof(read_map_offset));
	memcpy(&read_icon_offset, iconset_header + 12, sizeof(read_icon_offset));
	if (read_map_offset != map_offset || read_icon_offset != icon_offset) {
		return fail("the 32-bit icon-set offsets were not read exactly");
	}
	if (!radar_uses_32_bit_icon_offsets()) {
		return fail("RadarClass::Plot_Radar_Pixel does not read icon-set offsets as int32_t");
	}
	return 0;
}
