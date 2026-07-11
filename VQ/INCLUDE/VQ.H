/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQ_H
#define VQ_H

/* VQHeader - VQ header structure.
 *
 * ImageSize       - Compressed image size 
 * ImageWidth      - Image x-dimension
 * ImageHeight     - Image y-dimension
 * BlockWidth      - Block x-dimension
 * BlockHeight     - Block y-dimension
 * BlockType       - Block type
 * PaletteRange    - Number of palette colors
 * Num1Color       - Number of 1-color blocks & 1-color colors
 * CodebookSize    - Number of actual codebook entries
 * CodingFlag      - Flag for 2-color blocks
 * FrameDiffMethod - Frame differencing method
 * ForcedPalette   - Force a palette on image
 * F555Palette     - Flag for output 15-bit palette
 * VQVersion       - VQ Version #
 * pad[5]          - Pad out to 40 bytes total
 */
typedef struct _VQHeader {
	unsigned long  ImageSize;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned short BlockWidth;
	unsigned short BlockHeight;
	unsigned short BlockType;
	unsigned short PaletteRange;
	unsigned short Num1Color;
	unsigned short CodebookSize;
	unsigned short CodingFlag;
	unsigned short FrameDiffMethod;
	unsigned short ForcedPalette;
	unsigned short F555Palette;
	unsigned short VQVersion;
	unsigned short pad[5];
} VQHeader;

#endif /* VQ_H */
