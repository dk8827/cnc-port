/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RECT_H
#define RECT_H

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

#include	<stddef.h>

class Rect
{
	public:
		Rect(int x=0, int y=0, int w=0, int h=0);

		Rect const Intersect(Rect const & rectangle, int * x=NULL, int * y=NULL) const;
		friend Rect const Union(Rect const & rect1, Rect const & rect2);

		bool Is_Valid(void) const;
		int Size(void) const {return(Width*Height);}

//	private:
		int X;
		int Y;
		int Width;
		int Height;
};


#endif

