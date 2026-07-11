/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef FACE_H
#define FACE_H

// Enumerations of the facing values returned from Desired_Facing().
typedef enum DirType {
	DIR_MIN=0,
	DIR_N=0,
	DIR_NE=1<<5,
	DIR_E=2<<5,
	DIR_SE=3<<5,
	DIR_S=4<<5,
	DIR_SW=5<<5,
	DIR_W=6<<5,
	DIR_NW=7<<5,
	DIR_MAX=255
} DirType;

// Operators that allow simple math with DirType.
inline DirType operator + (DirType f1, DirType f2)
{
	return (DirType)(((int)f1 + (int)f2) & 0x00FF);
}
inline DirType operator + (DirType f1, int f2)
{
	return (DirType)(((int)f1 + (int)f2) & 0x00FF);
}
inline DirType operator - (DirType f1, DirType f2)
{
	return (DirType)(((int)f1 - (int)f2) & 0x00FF);
}
inline DirType operator - (DirType f1, int f2)
{
	return (DirType)(((int)f1 - (int)f2) & 0x00FF);
}


// Function prototypes.
DirType Desired_Facing8(int x1, int y1, int x2, int y2);
DirType Desired_Facing256(int srcx, int srcy, int dstx, int dsty);

#endif



