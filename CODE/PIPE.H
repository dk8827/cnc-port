/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef PIPE_H
#define PIPE_H

#include	<stddef.h>

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
**	A "push through" pipe interface abstract class used for such purposes as compression
**	and translation of data. In STL terms, this is functionally similar to an output
**	iterator but with a few enhancements. A pipe class object that is not derived into
**	another useful class serves only as a pseudo null-pipe. It will accept data but
**	just throw it away but pretend that it sent it somewhere.
*/
class Pipe
{
	public:
		Pipe(void) : ChainTo(0), ChainFrom(0) {}
		virtual ~Pipe(void);

		virtual int Flush(void);
		virtual int End(void) {return(Flush());}
		virtual void Put_To(Pipe * pipe);
		void Put_To(Pipe & pipe) {Put_To(&pipe);}
		virtual int Put(void const * source, int slen);

		/*
		**	Pointer to the next pipe segment in the chain.
		*/
		Pipe * ChainTo;
		Pipe * ChainFrom;

	private:

		/*
		**	Disable the copy constructor and assignment operator.
		*/
		Pipe(Pipe & rvalue);
		Pipe & operator = (Pipe const & pipe);
};

#endif
