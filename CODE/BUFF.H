/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CCBUFF_H
#define CCBUFF_H


/*
**	The "bool" integral type was defined by the C++ committee in
**	November of '94. Until the compiler supports this, use the following
**	definition.
*/
#ifndef __BORLANDC__
#ifndef TRUE_FALSE_DEFINED
#define TRUE_FALSE_DEFINED
enum {false=0,true=1};
typedef int bool;
#endif
#endif

/*
**	A general purpose buffer pointer handler object. It holds not only the pointer to the
**	buffer, but its size as well. By using this class instead of separate pointer and size
**	values, function interfaces and algorithms become simpler to manage and understand.
*/
class Buffer {
	public:
		Buffer(char * ptr, long size=0);
		Buffer(void * ptr=0, long size=0);
		Buffer(void const * ptr, long size=0);
		Buffer(long size);
		Buffer(Buffer const & buffer);
		~Buffer(void);

		Buffer & operator = (Buffer const & buffer);
		operator void * (void) const {return(BufferPtr);}
		operator char * (void) const {return((char *)BufferPtr);}

		void Reset(void);
		void * Get_Buffer(void) const {return(BufferPtr);}
		long Get_Size(void) const {return(Size);}
		bool Is_Valid(void) const {return(BufferPtr != 0);}

	protected:

		/*
		**	Pointer to the buffer memory.
		*/
		void * BufferPtr;

		/*
		**	The size of the buffer memory.
		*/
		long Size;

		/*
		**	Was the buffer allocated by this class? If so, then this class
		**	will be responsible for freeing the buffer.
		*/
		bool IsAllocated;
};


#endif
