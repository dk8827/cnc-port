/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BAR_H
#define BAR_H

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

#include "fixed.h"


/*
**	This is a manager for a progress (or other) bargraph. Such a graph consists of a fill
**	and a background region. The fill percentage of the bargraph is controlled by an
**	update value. The bargraph can be optionally outlined.
*/
class ProgressBarClass
{
	public:
		ProgressBarClass(int x, int y, int width, int height, int forecolor, int backcolor, int bordercolor=0);

		bool Update(fixed value);
		void Redraw(void) const;

	private:

		void Outline(void) const;
		bool Is_Horizontal(void) const;
		bool Is_Outlined(void) const {return(BorderColor != 0);}

		/*
		**	This is the upper left coordinates of the bargraph.
		*/
		int X,Y;

		/*
		**	This is the dimensions of the bargraph.
		*/
		int Width, Height;

		/*
		**	These are the colors to use when drawing the progress bar.
		*/
		int BarColor;
		int BackColor;
		int BorderColor;

		/*
		**	This is the current value of the bargraph.
		*/
		fixed CurrentValue;

		/*
		**	This is the current value as of the last time the bargraph was rendered.
		*/
		fixed LastDisplayCurrent;

		/*
		**	If the bargraph has been drawn at least once, then this flag will
		**	be true.
		*/
		unsigned IsDrawn:1;
};


#endif
