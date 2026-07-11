/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMTARGA_H
#define VQMTARGA_H

/*---------------------------------------------------------------------------
 * Targa Header definitions
 *-------------------------------------------------------------------------*/

/* TGAHeader - Targa Image File header.
 *
 * IDLength        - Size of Image ID field
 * ColorMapType    - Color map type.
 * ImageType       - Image type code.
 * CMapStart       - Color map origin.
 * CMapLength      - Color map length.
 * CMapDepth       - Depth of color map entries.
 * XOffset         - X origin of image.
 * YOffset         - Y origin of image.
 * Width           - Width of image.
 * Height          - Height of image.
 * PixelDepth      - Image pixel size
 * ImageDescriptor - Image descriptor byte.
 */
typedef struct _TGAHeader {
	char  IDLength;
	char  ColorMapType;
	char  ImageType;
	short CMapStart;
	short CMapLength;
	char  CMapDepth;
	short XOffset;
	short YOffset;
	short Width;
	short Height;
	char  PixelDepth;
	char  ImageDescriptor;
} TGAHeader;

/* ImageType definiton */
#define TGA_NOIMAGE           0  /* No image data included in file */
#define TGA_CMAPPED           1  /* Color-mapped image data */
#define TGA_TRUECOLOR         2  /* Truecolor image data */
#define TGA_MONO              3  /* Monochrome image data */
#define TGA_CMAPPED_ENCODED   9  /* Color-mapped image data (Encoded) */
#define TGA_TRUECOLOR_ENCODED 10 /* Truecolor image data (Encoded) */
#define TGA_MONO_ENCODED      11 /* Monochrome image data (Encoded) */

/* ImageDescriptor definition */
#define TGAF_ATTRIB_BITS (0x0F<<0) /* Number of attribute bits per pixel */
#define TGAF_XORIGIN     (1<<4)
#define TGAF_YORIGIN     (1<<5)

/*---------------------------------------------------------------------------
 * Targa Handle definitions
 *-------------------------------------------------------------------------*/

/* TGAHandle - Targa Image File handle.
 *
 * fh     - File handle returned by open().
 * mode   - Access mode.
 * header - TGAHeader structure.
 */
typedef struct _TGAHandle {
	short          fh;
	unsigned short mode;
	TGAHeader      header;
} TGAHandle;

/* Access modes. */
#define TGA_READMODE  0
#define TGA_WRITEMODE 1
#define TGA_RDWRMODE  2

/* Error codes */
#define TGAERR_OPEN         -1
#define TGAERR_READ         -2
#define TGAERR_WRITE        -3
#define TGAERR_SYNTAX       -4
#define TGAERR_NOMEM        -5
#define TGAERR_NOTSUPPORTED -6
 
/*---------------------------------------------------------------------------
 * Function prototypes
 *-------------------------------------------------------------------------*/

TGAHandle *OpenTarga(char *, unsigned short);
void CloseTarga(TGAHandle *);
long LoadTarga(char *, char *, char *);
long SaveTarga(char *, TGAHeader *, char *, char *);
void XFlipTarga(TGAHeader *, char *);
void YFlipTarga(TGAHeader *, char *);

#endif /* VQMTARGA_H */

