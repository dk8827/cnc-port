/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"shapipe.h"


/***********************************************************************************************
 * SHAPipe::Put -- Pass data through the pipe, but use it to build a SHA digest.               *
 *                                                                                             *
 *    This pipe segment will not modify the data, but it will examine the data and use it when *
 *    building a SHA digest.                                                                   *
 *                                                                                             *
 * INPUT:   source   -- Pointer to the data to flow through the pipe.                          *
 *                                                                                             *
 *          length   -- The number of bytes to submit.                                         *
 *                                                                                             *
 * OUTPUT:  Returns with the actual number of bytes output at the distant final end of the     *
 *          pipe chain.                                                                        *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int SHAPipe::Put(void const * source, int slen)
{
	SHA.Hash(source, slen);
	return(Pipe::Put(source, slen));
}


/***********************************************************************************************
 * SHAPipe::Result -- Fetches the current SHA value.                                           *
 *                                                                                             *
 *    This routine will return the SHA digest for the data that has passed through this        *
 *    link in the pipe chain. It is a non-destructive read.                                    *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the buffer to hold the SHA digest. This buffer must be      *
 *                      20 bytes long.                                                         *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes copied into the buffer. This will be 20.          *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/03/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int SHAPipe::Result(void * result) const
{
	return(SHA.Result(result));
}


