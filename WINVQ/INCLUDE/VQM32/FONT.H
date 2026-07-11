/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMFONT_H
#define VQMFONT_H

/* Font: A Westwood style font.
 *
 * Size       - Size of font.
 * CompMethod - Compression method of font. (0 = none)
 * NumBlks    - Number of data blocks.
 * InfoBlk    - Offset to font information block.
 * OffsetBlk  - Offset to character offset block.
 * WidthBlk   - Offset to character width block.
 * DataBlk    - Offset to character data block.
 * HeightBlk  - Offset to character height block.
 */
typedef struct _Font {
	unsigned short Size;
	unsigned char  CompMethod;
	unsigned char  NumBlks;
	unsigned short InfoBlk;
	unsigned short OffsetBlk;
	unsigned short WidthBlk;
	unsigned short DataBlk;
	unsigned short HeightBlk;
} Font;

typedef struct _FontInfo {
	long huh;
	unsigned char MaxHeight;
	unsigned char MaxWidth;
} FontInfo;

#ifdef __cplusplus
extern "C" {
#endif

extern void const *FontPtr;
extern int FontXSpacing;
extern int FontYSpacing;

#ifdef __cplusplus
}
#endif

extern char FontWidth;
extern char FontHeight;
extern char *FontWidthBlockPtr;

/* Function prototypes. */
void *cdecl Load_Font(char const *name);
void *cdecl Set_Font(void const *font);
unsigned short __cdecl String_Pixel_Width(char const *string);

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __WATCOMC__
long __cdecl __saveregs Char_Pixel_Width(char chr);
#else
long __cdecl Char_Pixel_Width(char chr);
#endif

#ifdef __cplusplus
}
#endif

#endif /* VQMFONT_H */

