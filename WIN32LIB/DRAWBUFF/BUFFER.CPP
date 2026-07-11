/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BUFFER_H
#include "buffer.h"
#endif

/*=========================================================================*/
/* The following PRIVATE functions are in this file:                       */
/*=========================================================================*/


/*= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =*/

/***************************************************************************
 * BC::BufferClass -- The standard constructor for a buffer class          *
 *                                                                         *
 * INPUT:		VOID *	buffer to which should be included in buffer class *
 *					LONG		size of the buffer which we included					*
 *                                                                         *
 * OUTPUT:     NONE                                                        *
 *                                                                         *
 * WARNINGS:   If the buffer passed to this function is equal to NULL,     *
 *					the buffer will be allocated using new.							*
 *                                                                         *
 * HISTORY:                                                                *
 *   06/01/1994 PWG : Created.                                             *
 *=========================================================================*/
BufferClass::BufferClass(VOID *buffer, long size)
{
	Size			= size;								// find size of physical buffer

	if (buffer) {										// if buffer is specified
		Buffer			= (BYTE *)buffer;			//		point to it and mark
		Allocated		= FALSE;						//		it as user allocated
	} else {
		Buffer			= new BYTE[Size];			// otherwise allocate it and
		Allocated		= TRUE;						//		mark it system alloced
	}
}

/***************************************************************************
 * BC::BufferClass -- constructor for BufferClass with size only    			*
 *                                                                         *
 * INPUT:		LONG the size of the buffer that needs to be allocated		*
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/01/1994 PWG : Created.                                             *
 *=========================================================================*/
BufferClass::BufferClass(long size)
{
	Size				= size;
	Buffer			= new BYTE[Size];			// otherwise allocate it and
	Allocated		= TRUE;						//		mark it system alloced
}

/***************************************************************************
 * BC::BufferClass -- The default (void) constructor for a buffer class    *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * NOTES:   	The primary function of this class is to be called by a     *
 *					derived class which will fill in the values after the			*
 *					fact.																			*
 *                                                                         *
 * HISTORY:                                                                *
 *   06/01/1994 PWG : Created.                                             *
 *=========================================================================*/
BufferClass::BufferClass(VOID)
{
	Buffer		= NULL;
	Size			= 0;
	Allocated	= FALSE;
}

/***************************************************************************
 * BC::~BUFFERCLASS -- The destructor for the buffer class                 *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/01/1994 PWG : Created.                                             *
 *=========================================================================*/
BufferClass::~BufferClass(VOID)
{
	if (Allocated) {
		delete[] Buffer;
	}
}
