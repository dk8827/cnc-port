/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VOCFILE_H
#define VOCFILE_H

/* VOC file header.
 *
 * type   - File type description
 * offset - Offset of data block from the start of VOC file.
 * ver    - File format version number
 * id     - File identification code.
 */
typedef struct _VOCHeader {
	char           type[0x14];
	unsigned short offset;
	unsigned short ver;
	unsigned short id;
} VOCHeader;

/* VOC sub-block block types */
#define VBT_TERMINATE 0  /* Last block of file (no size field) */
#define VBT_VOICEDATA 1  /* New set of voice data */
#define VBT_VOICECONT 2  /* Continuation of voice data */
#define VBT_SILENCE   3  /* Silence period */
#define VBT_MARKER    4  /* Syncronization marker */
#define VBT_ASCII     5  /* NULL terminated string */
#define VBT_REPEAT    6  /* Mark beginning of repeat loop */
#define VBT_ENDREPEAT 7  /* Mark end of repeat loop */
#define VBT_EXTENDED  8

#define IS_VOC(a,b) (((~a)+0x1234)==b)
#define BLOCK_LEN(a) ((a&0x00FFFFFFL))

#endif  /* VOCFILE_H */


