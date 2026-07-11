/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "crc.h"
#include <string.h>


/***********************************************************************************************
 * CRCEngine::operator() -- Submits one byte of data to the CRC engine.                        *
 *                                                                                             *
 *    This routine will take the specified byte of data and submit it to the CRC engine        *
 *    for processing. This routine is designed to be as fast as possible since the typical     *
 *    use of this routine is to feed one of presumably many byte sized chunks of data to the   *
 *    CRC engine.                                                                              *
 *                                                                                             *
 * INPUT:   datum -- One byte of data to submit to the CRC engine.                             *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   If possible, use the buffer/size operator to submit data rather than repeated   *
 *             calls to this routine.                                                          *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   03/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void CRCEngine::operator() (char datum)
{
	StagingBuffer.Buffer[Index++] = datum;

	if (Index == sizeof(StagingBuffer.Composite))  {
		CRC = Value();
		StagingBuffer.Composite = 0;
		Index = 0;
	}
}


/***********************************************************************************************
 * CRCEngine::operator() -- Submits an arbitrary data block to the CRC engine.                 *
 *                                                                                             *
 *    This routine will submit the specified block to the CRC engine. The block can be of      *
 *    arbitrary length.                                                                        *
 *                                                                                             *
 * INPUT:   buffer   -- Pointer to the buffer that contains the data. The buffer will not      *
 *                      be modified.                                                           *
 *                                                                                             *
 *          length   -- The length of the buffer (in bytes).                                   *
 *                                                                                             *
 * OUTPUT:  Returns with the current CRC value accumulated so far.                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   03/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
long CRCEngine::operator() (void const * buffer, int length)
{
	if (buffer != NULL && length > 0)  {
		char const * dataptr = (char const *)buffer;
		int bytes_left = length;

		/*
		**	If there are any leader bytes (needed to fill the staging buffer)
		**	then process those by first using them to fill up the staging
		**	buffer. The bulk of the data block will be processed by the high
		**	speed longword processing loop.
		*/
		while (bytes_left && Buffer_Needs_Data()) {
			operator()(*dataptr);
			dataptr++;
			bytes_left--;
		}

		/*
		**	Perform the fast 'bulk' processing by reading long word sized
		**	data blocks.
		*/
		int longcount = bytes_left / sizeof(int32_t);		// Whole 32 bit elements remaining.
		while (longcount--) {
			int32_t word;
			memmove(&word, dataptr, sizeof(word));
			CRC = (int32_t)(CRCEngine::Rotate_Left_32((uint32_t)CRC, 1) + (uint32_t)word);
			dataptr += sizeof(word);
			bytes_left -= sizeof(word);
		}

		/*
		**	If there are remainder bytes, then process these by adding them
		**	to the staging buffer.
		*/
		while (bytes_left) {
			operator()(*dataptr);
			dataptr++;
			bytes_left--;
		}
	}

	/*
	**	Return the current CRC value.
	*/
	return(Value());
}
