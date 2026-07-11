#include "shape.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

static int fail(char const *message)
{
	fprintf(stderr, "FAIL: %s\n", message);
	return 1;
}

static void put_u16(unsigned char *ptr, unsigned int value)
{
	ptr[0] = (unsigned char)(value & 0xff);
	ptr[1] = (unsigned char)((value >> 8) & 0xff);
}

static void put_u32(unsigned char *ptr, unsigned int value)
{
	ptr[0] = (unsigned char)(value & 0xff);
	ptr[1] = (unsigned char)((value >> 8) & 0xff);
	ptr[2] = (unsigned char)((value >> 16) & 0xff);
	ptr[3] = (unsigned char)((value >> 24) & 0xff);
}

int main(void)
{
	if (offsetof(Shape_Type, Width) != 3) return fail("Shape_Type must be packed");
	if (offsetof(Shape_Type, DataLength) != 8) return fail("Shape_Type DataLength offset changed");
	if (sizeof(((ShapeBlock_Type *)0)->Offsets[0]) != 4) return fail("shape offsets must be 32-bit");

	unsigned char block[128];
	memset(block, 0, sizeof(block));

	put_u16(block, 2);
	put_u32(block + 2, 8);
	put_u32(block + 6, 32);

	Shape_Type *first = (Shape_Type *)(block + 10);
	first->ShapeType = MAKESHAPE_NOCOMP;
	first->Height = 3;
	first->Width = 5;
	first->OriginalHeight = 7;
	first->ShapeSize = 10;
	first->DataLength = 15;

	Shape_Type *second = (Shape_Type *)(block + 34);
	second->ShapeType = MAKESHAPE_NOCOMP;
	second->Height = 11;
	second->Width = 13;
	second->OriginalHeight = 17;
	second->ShapeSize = 10;
	second->DataLength = 143;

	if (Extract_Shape_Count(block) != 2) return fail("shape count mismatch");
	if (Extract_Shape(block, 0) != first) return fail("first shape pointer mismatch");
	if (Extract_Shape(block, 1) != second) return fail("second shape pointer mismatch");
	if (Extract_Shape(block, -1) != 0) return fail("negative shape index should fail");
	if (Extract_Shape(block, 2) != 0) return fail("out-of-range shape index should fail");

	if (Get_Shape_Width(first) != 5) return fail("packed width read mismatch");
	if (Get_Shape_Height(first) != 3) return fail("packed height read mismatch");
	if (Get_Shape_Original_Height(first) != 7) return fail("packed original-height read mismatch");
	if (Get_Shape_Uncomp_Size(first) != 15) return fail("packed data-length read mismatch");

	return 0;
}
