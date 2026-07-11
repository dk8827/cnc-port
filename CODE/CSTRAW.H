/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CSTRAW_H
#define CSTRAW_H

#include	"straw.h"
#include	"buff.h"

/*
**	This class handles transfer of data by perform regulated requests for data from the next
**	class in the chain. It performs no translation on the data. By using this segment in a
**	straw chain, data throughput can be regulated. This can yield great performance increases
**	when dealing with a file source.
*/
class CacheStraw : public Straw
{
	public:
		CacheStraw(Buffer const & buffer) : BufferPtr(buffer), Index(0), Length(0) {}
		CacheStraw(int length=4096) : BufferPtr(length), Index(0), Length(0) {}
		virtual int Get(void * source, int slen);

	private:
		Buffer BufferPtr;
		int Index;
		int Length;

		bool Is_Valid(void) {return(BufferPtr.Is_Valid());}
		CacheStraw(CacheStraw & rvalue);
		CacheStraw & operator = (CacheStraw const & pipe);
};



#endif

