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
#define BUFFER_H


/*=========================================================================*/
/* If we have not already loaded the standard library header, than we can	*/
/*		load it.																					*/
/*=========================================================================*/
#ifndef WWSTD_H
#include "wwstd.h"
#endif

class GraphicViewPortClass;

/*=========================================================================*/
/* BufferClass - A base class which holds buffer information including a	*/
/*		pointer and the size of the buffer.												*/
/*=========================================================================*/
class BufferClass {
	public:
		/*===================================================================*/
		/* Define the base constructor and destructors for the class			*/
		/*===================================================================*/
		BufferClass(void *ptr, long size);
		BufferClass(long size);
		BufferClass();
		~BufferClass();
		/*===================================================================*/
		/* Define functions which work with the buffer class.						*/
		/*===================================================================*/
		long To_Page(GraphicViewPortClass &view);
		long To_Page(int w, int h, GraphicViewPortClass &view);
		long To_Page(int x, int y, int w, int h, GraphicViewPortClass &view);

		/*===================================================================*/
		/* define functions to get at the protected data members					*/
		/*===================================================================*/
		void	*Get_Buffer(void);
		long	Get_Size(void);

	private:
		/*===================================================================*/
		/* Define the operators we do not want to happen which are the copy	*/
		/* and equal constructors.  These are bad because the Allocated flag	*/
		/*	could be copied and the associated buffer freed.  If this were to	*/
		/*	gappen it could cause weird general protection fault.					*/
		/*===================================================================*/
		BufferClass(BufferClass const &);
		BufferClass &operator=(BufferClass const &);

	protected:
		void	*Buffer;
		long	Size;
		BOOL	Allocated;
};
/***************************************************************************
 * BC::GET_SIZE -- Returns the buffer size of the BufferClass instance     *
 *                                                                         *
 * INPUT:		none                                                        *
 *                                                                         *
 * OUTPUT:     long the size of the buffer                                 *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline long BufferClass::Get_Size(void)
{
	return(Size);
}
/***************************************************************************
 * BC::GET_BUFFER -- Returns pointer to buffer inherent to BufferClass 		*
 *                                                                         *
 * INPUT:			none                                                     *
 *                                                                         *
 * OUTPUT:        void * to the inherent buffer.                           *
 *                                                                         *
 * HISTORY:                                                                *
 *   06/01/1994 PWG : Created.                                             *
 *=========================================================================*/
inline void *BufferClass::Get_Buffer(void)
{
	return(Buffer);
}
#endif
