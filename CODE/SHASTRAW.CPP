/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"shastraw.h"


/***********************************************************************************************
 * SHAStraw::Get -- Fetch data from the straw and process the SHA with the data.               *
 *                                                                                             *
 *    This routine will fetch the requested data and as it passes through this straw it will   *
 *    submit it to the SHA processor. The data that passes through is unmodified by this       *
 *    straw segment.                                                                           *
 *                                                                                             *
 * INPUT:   source   -- Pointer to the buffer that will hold the requested data.               *
 *                                                                                             *
 *          length   -- The length of the data requested.                                      *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes stored in the buffer. If this number is less      *
 *          than the number requested, then this indicates that the data stream has been       *
 *          exhausted.                                                                         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int SHAStraw::Get(void * source, int slen)
{
	if (source == NULL || slen < 1) {
		return(0);
	}

	int counter = Straw::Get(source, slen);
	SHA.Hash(source, counter);
	return(counter);
}


/***********************************************************************************************
 * SHAStraw::Result -- Fetches the current SHA digest.                                         *
 *                                                                                             *
 *    Use this routine to fetch the current SHA digest from the straw. It will return the      *
 *    digest of the data that has passed through this straw segment.                           *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the buffer to hold the message digest. The buffer must be   *
 *                      20 bytes long.                                                         *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes stored into the digest buffer. This will always   *
 *          be 20.                                                                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int SHAStraw::Result(void * result) const
{
	return(SHA.Result(result));
}
