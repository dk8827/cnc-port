/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQFILE_H
#define VQFILE_H

#include <vqm32/iff.h>

/* Disable Watcom structure alignment. */
#ifdef __WATCOMC__
#pragma pack(1);
#endif

/*---------------------------------------------------------------------------
 * STRUCTURE DEFINITIONS AND RELATED INFORMATION
 *-------------------------------------------------------------------------*/

/* VQHeader: VQ header.
 *
 * Version     - VQ file version
 * Flags       - Various flags (see below)
 * ImageWidth  - Width of constructed image in pixels.
 * ImageHeight - Height of contructed image in pixels.
 * BlockType   - Type of codebook block. (EX: rectangle)
 * BlockWidth  - Width of a codebook block in pixels.
 * BlockHeight - Height of a codebook block in pixels.
 * BlockDepth  - Depth of a codebook block in bits.
 * CBEntries   - Number of entries in the codebook.
 * VPtrType    - Vector pointer type. (IE: Banked)
 * PalStart    - Starting entry position of palette.
 * PalLength   - Number of palette entries the palette.
 * PalDepth    - Depth of palette entries in bits.
 * ColorModel  - Color model of this VQ
 */
typedef struct _VQHeader {
	short Version;
	short Flags;
	short ImageWidth;
	short ImageHeight;
	short BlockType;
	short BlockWidth;
	short BlockHeight;
	short BlockDepth;
	short CBEntries;
	short VPtrType;
	short PalStart;
	short PalLengh;
	short PalDepth;
	short ColorModel;
} VQHeader;


/* VQ file flags */
#define VQHB_CBCOMP 0 /* Codebook compressed */
#define VQHB_CTCOMP 1 /* Color table compressed */
#define VQHB_VPCOMP 2 /* Vector pointers compressed */
#define VQHF_CBCOMP (1<<VQHB_CBCOMP)
#define VQHF_CTCOMP (1<<VQHB_CTCOMP)
#define VQHF_VPCOMP (1<<VQHB_VPCOMP)

/* Block types */
#define VQBT_RECT 0 /* Rectangle Width X Height */

/* Color models */
#define VQCM_PALETTED 0 /* Palette (8 bit indices) */
#define VQCM_RGBTRUE  1 /* RBG truecolor (24 bit) */
#define VQCM_YBRTRUE  2 /* YCbCr truecolor */


/*---------------------------------------------------------------------------
 * VQ FILE CHUNK ID DEFINITIONS
 *-------------------------------------------------------------------------*/

#define ID_VQHR MAKE_ID('V','Q','H','R') /* VQ Header */
#define ID_VQCB MAKE_ID('V','Q','C','B') /* VQ Codebook */
#define ID_VQCT MAKE_ID('V','Q','C','T') /* VQ Color Table (palette) */
#define ID_VQVP MAKE_ID('V','Q','V','P') /* VQ Vector pointers */

#ifdef __WATCOMC__
#pragma pack();
#endif

#endif /* VQFILE_H */

