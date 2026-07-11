/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "crcpipe.h"


/***********************************************************************************************
 * CRCPipe::Put -- Retrieves the data bytes specified and calculates CRC on it.                *
 *                                                                                             *
 *    This routine will fetch the number of bytes requested from the straw. The data is        *
 *    not modified by this straw segment, but it is examined by the CRC engine in order to     *
 *    keep an accurate CRC of the data that passes through this routine.                       *
 *                                                                                             *
 * INPUT:   source   -- Pointer to the buffer that will hold the data requested.               *
 *                                                                                             *
 *          length   -- The number of bytes requested.                                         *
 *                                                                                             *
 * OUTPUT:  Returns with the actual number of bytes stored into the buffer. If this number is  *
 *          less than the number requested, then this indicates that the data stream has been  *
 *          exhausted.                                                                         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int CRCPipe::Put(void const * source, int slen)
{
	CRC(source, slen);
	return(Pipe::Put(source, slen));
}


/***********************************************************************************************
 * CRCPipe::Result -- Fetches the current CRC of the data.                                     *
 *                                                                                             *
 *    This routine will return the CRC of the data that has passed through the pipe up to      *
 *    this time.                                                                               *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the CRC value.                                                        *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
long CRCPipe::Result(void) const
{
	return(CRC());
}

