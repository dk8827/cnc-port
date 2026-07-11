/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMMIXFILE_H
#define VQMMIXFILE_H

/* Disable structure alignment.*/
#ifdef __WATCOMC__
#pragma pack(1);
#endif

/*---------------------------------------------------------------------------
 * STRUCTURE DEFINITIONS
 *-------------------------------------------------------------------------*/

/* MIXHeader: Mix file data header.
 *
 * Count - Number of entries contained in this mix file.
 * Size  - Size of Mix file.
 */
typedef struct _MIXHeader {
	short Count;
	long  Size;
} MIXHeader;

/* MIXSubBlock: Mix file entry descriptor.
 *
 * CRC    - Unique entry identifier.
 * Offset - Offset from beginning of data segment to entry.
 * Size   - Size of entry.
 */
typedef struct _MIXSubBlock {
	long CRC;
	long Offset;
	long Size;
} MIXSubBlock;

/* MIXHandle: Mix file handle.
 *
 * Name    - Pointer to the name of the mix file this handle is for.
 * Size    - Size of entire mix file.
 * FH      - DOS file handle of opened entry.
 * Count   - Number of files contained in this mix.
 * Entries - Array of 'Count' MIXSubBlock structure entries.
 */
typedef struct _MIXHandle {
	char        *Name;
	long        Size;
	long        FH;
	long        Count;
	MIXSubBlock Entries[];
} MIXHandle;

/*---------------------------------------------------------------------------
 * PROTOTYPES
 *-------------------------------------------------------------------------*/

MIXHandle *OpenMix(char *name);
void CloseMix(MIXHandle *mix);
long OpenMixEntry(MIXHandle *mix, char *name);

/* Restore original alignment */
#ifdef __WATCOMC__
#pragma pack();
#endif

#endif /* VQMMIXFILE_H */

