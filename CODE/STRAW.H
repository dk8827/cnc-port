/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef STRAW_H
#define STRAW_H

#include <stdlib.h>

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
**	This is a demand driven data carrier. It will retrieve the byte request by passing
**	the request down the chain (possibly processing on the way) in order to fulfill the
**	data request. Without being derived, this class merely passes the data through. Derived
**	versions are presumed to modify the data in some useful way or monitor the data
**	flow.
*/
class Straw
{
	public:
		Straw(void) : ChainTo(0), ChainFrom(0) {}
		virtual ~Straw(void);

		virtual void Get_From(Straw * pipe);
		void Get_From(Straw & pipe) {Get_From(&pipe);}
		virtual int Get(void * buffer, int slen);

		/*
		**	Pointer to the next pipe segment in the chain.
		*/
		Straw * ChainTo;
		Straw * ChainFrom;

	private:

		/*
		**	Disable the copy constructor and assignment operator.
		*/
		Straw(Straw & rvalue);
		Straw & operator = (Straw const & pipe);
};


#endif
