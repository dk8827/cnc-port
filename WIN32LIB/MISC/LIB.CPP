/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include <dos.h>
#include <stdio.h>
#include <string.h>
#include "misc.h"

//PRIVATE unsigned Divide_With_Round(unsigned num, unsigned den);


/***************************************************************************
 * Divide_With_Round -- Divides integers and round to nearest integer.     *
 *                                                                         *
 * INPUT:         int numberator.                                         *
 *                int denominator.                                        *
 *                                                                         *
 * OUTPUT:        Returns value rounded.                                   *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   02/13/1992  SB : Created.                                             *
 *=========================================================================*/
static unsigned Divide_With_Round(unsigned num, unsigned den)
{
	// return num/den + (0 ro 1).  1 if the remainder is more than half the denominator.
	return( (num / den) + (unsigned)((num % den) >= ((den + 1) >> 1)) );
}

#define HSV_BASE 255 // This is used to get a little better persion on HSV conversion.
#define RGB_BASE 63  // Not 64, this is really the max value.


/***************************************************************************
 * Convert_RGB_To_HSV -- Converts RGB to RSV coordinates.                  *
 *                                                                         *
 * INPUT:      int r,g, and b values.                                     *
 *             int *h, *s, and *v pointers.                              	*
 *                                                                         *
 * OUTPUT:     Assigns values to *h, *s, and *v.                           *
 *                                                                         *
 * WARNINGS:   The reason we use a different base for HSV then RGB is      *
 *             because we loose alot of persision by not using floating    *
 *             point.  Using the same base value (63) made it so that      *
 *             about 50% of the time one RGB value would be one different  *
 *             then the original if you went from RGB to HSV to RGB.       *
 *             Using 255 drop it down to about 9% of the time we get an    *
 *             off value.  To get it perfect, we would have to make the    *
 *             HSV base larger - but then you need to do all calculations  *
 *             in long instead of unsigned int.                                   *
 * HISTORY:                                                                *
 *   02/11/1992  SB : Created.                                             *
 *=========================================================================*/
void Convert_RGB_To_HSV(unsigned int r, unsigned int g, unsigned int b, unsigned int *h, unsigned int *s, unsigned int *v)
{
 	unsigned int m, r1, g1, b1, tmp;

	// Convert RGB base to HSV base.
	r = Divide_With_Round((r * HSV_BASE), RGB_BASE);
	g = Divide_With_Round((g * HSV_BASE), RGB_BASE);
	b = Divide_With_Round((b * HSV_BASE), RGB_BASE);

	// Set hue to default.
	*h = 0;

	// Set v = Max(r,g,b) to find dominant primary color.
	*v = (r > g) ? r : g;
	if (b > *v) *v = b;

	// Set m = min(r,g,b) to find amount of white.
	m = (r < g) ? r : g;
	if (b < m) m = b;

	// Determine the normalized saturation.
	if (*v != 0) {
		*s = Divide_With_Round( (*v - m) * HSV_BASE ,*v);
	} else {
		*s = 0;
	}

	if (*s != 0) {
		tmp = *v - m;
	 	r1 = Divide_With_Round( (*v - r) * HSV_BASE, tmp);
	 	g1 = Divide_With_Round( (*v - g) * HSV_BASE, tmp);
	 	b1 = Divide_With_Round( (*v - b) * HSV_BASE, tmp);

		// Find effect of second most predominant color.
		// In which section of the hexagon of colors does the color lie?
		if ((*v) == r) {
		 	if (m == g) {
				*h = 5 * HSV_BASE + b1;
			} else {
				*h = 1 * HSV_BASE - g1;
			}
		} else {
			if ((*v) == g) {
			 	if (m == b) {
					*h = 1 * HSV_BASE + r1;
				} else {
					*h = 3 * HSV_BASE - b1;
				}
			} else {
				// *v == b
			 	if (m == r) {
					*h = 3 * HSV_BASE + g1;
				} else {
					
					*h = 5 * HSV_BASE - r1;
				}
			}
		}

		// Divide by six and round.
		*h = Divide_With_Round(*h, 6);
	}
}

/***************************************************************************
 * Convert_HSV_To_RGB -- Converts HSV cordinates to RGB values             *
 *                                                                         *
 * INPUT:      int h,s, and v coordinates                                 *
 *             int *r, *g, and *b pointers.                              	*
 *                                                                         *
 * OUTPUT:     Assigns values to *r, *g, and *b.                           *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   02/11/1992  SB : Created.                                             *
 *=========================================================================*/
void Convert_HSV_To_RGB(unsigned int h, unsigned int s, unsigned int v, unsigned int *r, unsigned int *g, unsigned int *b)
{
	unsigned int i;				// Integer part.
	unsigned int f;				// Fractional or remainder part.  f/HSV_BASE gives fraction.
	unsigned int tmp;			// Tempary variable to help with calculations.
	unsigned int values[7];	// Possible rgb values.  Don't use zero.


	h *= 6;
	f = h % HSV_BASE;

	// Set up possible red, green and blue values.
	values[1] =	
	values[2] = v;

	//
	// The following lines of code change 
	//	values[3] = (v * (HSV_BASE - ( (s * f) / HSV_BASE) )) / HSV_BASE;
	//	values[4] = values[5] = (v * (HSV_BASE - s)) / HSV_BASE;
	// values[6] = (v * (HSV_BASE - (s * (HSV_BASE - f)) / HSV_BASE)) / HSV_BASE;
	// so that the are rounded divides.
	//

	tmp = Divide_With_Round(s * f, HSV_BASE);
	values[3] = Divide_With_Round(v * (HSV_BASE - tmp), HSV_BASE);

	values[4] = 
	values[5] = Divide_With_Round(v * (HSV_BASE - s), HSV_BASE);

	tmp = HSV_BASE - Divide_With_Round(s * (HSV_BASE - f),  HSV_BASE);
	values[6] = Divide_With_Round(v * tmp, HSV_BASE);


	// This should not be rounded.
	i = h / HSV_BASE;

	i += (i > 4) ? -4 : 2;
	*r = Divide_With_Round(values[i] * RGB_BASE, HSV_BASE);

	i += (i > 4) ? -4 : 2;
	*b = Divide_With_Round(values[i] * RGB_BASE, HSV_BASE);

	i += (i > 4) ? -4 : 2;
	*g = Divide_With_Round(values[i] * RGB_BASE, HSV_BASE);
} 
