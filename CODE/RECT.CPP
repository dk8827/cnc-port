/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"rect.h"


/***********************************************************************************************
 * Rect::Rect -- Constructs a rectangle object.                                                *
 *                                                                                             *
 *    This will construct a rectangle object according to the parameters specified.            *
 *                                                                                             *
 * INPUT:   x,y   -- The X and Y values of the upper left corner of the rectangle.             *
 *                                                                                             *
 *          w,h   -- The width and height values of the rectangle.                             *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/22/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
Rect::Rect(int x, int y, int w, int h) :
	X(x),
	Y(y),
	Width(w),
	Height(h)
{
}


/***********************************************************************************************
 * Rect::Is_Valid -- Determines if the rectangle is valid.                                     *
 *                                                                                             *
 *    An invalid rectangle has values that do not make any sense. This is a useful state since *
 *    this can be used to determine if a rectangle has been initialized correctly or for       *
 *    detecting an error return condition for rectangle manipulation routines.                 *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  bool; Does this rectangle appear valid?                                            *
 *                                                                                             *
 * WARNINGS:   An invalid rectangle is one that has a width or height of less than one.        *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/22/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool Rect::Is_Valid(void) const
{
	return(Width > 0 && Height > 0);
}


/***********************************************************************************************
 * Rect::Intersect -- Find the intersection between two rectangles.                            *
 *                                                                                             *
 *    This routine will take the specified rectangle and use it like a "cookie cutter" on this *
 *    rectangle. The intersection of these two rectangles is returned. An optional X and       *
 *    Y parameter is supplied so that an absolute coordinate can be maintained to the new      *
 *    rectangle.                                                                               *
 *                                                                                             *
 * INPUT:   rectangle   -- Reference to the rectangle to use as a cookie cutter.               *
 *                                                                                             *
 *          x,y         -- Optional pointer to a coordinate that will be adjusted to stay      *
 *                         in an absolute position in coordinates even though it is a          *
 *                         relative offset.                                                    *
 *                                                                                             *
 * OUTPUT:  Returns with the rectangle that is the intersection of the one specified and       *
 *          this rectangle.                                                                    *
 *                                                                                             *
 * WARNINGS:   The rectangle returned may be invalid. This can occur if there is no legal      *
 *             intersection between the rectangles.                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/22/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
Rect const Rect::Intersect(Rect const & rectangle, int * x, int * y) const
{
	Rect rect(0, 0, 0, 0);			// Dummy (illegal) rectangle.
	Rect r = rectangle;				// Working rectangle.

	/*
	**	Both rectangles must be valid or else no intersection can occur. In such
	**	a case, return an illegal rectangle.
	*/
	if (!Is_Valid() || !rectangle.Is_Valid()) return(rect);

	/*
	**	The rectangle spills past the left edge.
	*/
	if (r.X < X) {
		r.Width -= X - r.X;
		r.X = X;
	}
	if (r.Width < 1) return(rect);

	/*
	**	The rectangle spills past top edge.
	*/
	if (r.Y < Y) {
		r.Height -= Y - r.Y;
		r.Y = Y;
	}
	if (r.Height < 1) return(rect);

	/*
	**	The rectangle spills past the right edge.
	*/
	if (r.X + r.Width > X + Width) {
		r.Width -= (r.X + r.Width) - (X + Width);
	}
	if (r.Width < 1) return(rect);

	/*
	**	The rectangle spills past the bottom edge.
	*/
	if (r.Y + r.Height > Y + Height) {
		r.Height -= (r.Y + r.Height) - (Y + Height);
	}
	if (r.Height < 1) return(rect);

	/*
	**	Adjust Height relative draw position according to Height new rectangle
	**	union.
	*/
	if (x != NULL) {
		*x -= (r.X-X);
	}
	if (y != NULL) {
		*y -= (r.Y-Y);
	}

	return(r);
}


Rect const Union(Rect const & rect1, Rect const & rect2)
{
	if (rect1.Is_Valid()) {
		if (rect2.Is_Valid()) {
			Rect result = rect1;

			if (result.X > rect2.X) {
				result.Width += result.X-rect2.X;
				result.X = rect2.X;
			}
			if (result.Y > rect2.Y) {
				result.Height += result.Y-rect2.Y;
				result.Y = rect2.Y;
			}
			if (result.X+result.Width < rect2.X+rect2.Width) {
				result.Width = ((rect2.X+rect2.Width)-result.X)+1;
			}
			if (result.Y+result.Height < rect2.Y+rect2.Height) {
				result.Height = ((rect2.Y+rect2.Height)-result.Y)+1;
			}
			return(result);
		}
		return(rect1);
	}
	return(rect2);
}
