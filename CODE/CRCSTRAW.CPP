/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "crcstraw.h"


/***********************************************************************************************
 * CRCStraw::Get -- Fetch the data requested and calculate CRC on it.                          *
 *                                                                                             *
 *    This routine will fetch the number of bytes requested. The data will not be modified     *
 *    by this straw segment, but the CRC engine will examine the data so as to keep an         *
 *    accurate CRC value.                                                                      *
 *                                                                                             *
 * INPUT:   source   -- Pointer to the buffer to hold the data requested.                      *
 *                                                                                             *
 *          length   -- The number of bytes requested.                                         *
 *                                                                                             *
 * OUTPUT:  Returns with the actual number of bytes stored in the buffer. If this number is    *
 *          less than that requested, then this indicates that the data stream has been        *
 *          exhausted.                                                                         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int CRCStraw::Get(void * source, int slen)
{
	if (source == NULL || slen < 1) {
		return(0);
	}

	int counter = Straw::Get(source, slen);
	CRC(source, counter);
	return(counter);
}


/***********************************************************************************************
 * CRCStraw::Result -- Returns with the CRC of all data passed through the straw.              *
 *                                                                                             *
 *    This routine will return the CRC value of the data that has passed through this straw    *
 *    segment.                                                                                 *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the CRC value of the data this straw segment has seen.                *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
long CRCStraw::Result(void) const
{
	return(CRC());
}
