/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"watcom.h"
#include "rgb.h"
#include	"hsv.h"
#include	"palette.h"

RGBClass const BlackColor(0, 0, 0);
PaletteClass PaletteClass::CurrentPalette;


/***********************************************************************************************
 * RGBClass::Adjust -- Adjust one RGB value toward another.                                    *
 *                                                                                             *
 *    This routine is used to modify an RGB value to proportionately match another RGB value   *
 *    according to the ratio parameter specified. Typical use of this routine is in palette    *
 *    fading from one palette to another or to black.                                          *
 *                                                                                             *
 * INPUT:   ratio    -- The ration of transformation. This value is in the form of 0 to 255,   *
 *                      with 0 being no change, and 255 being 100% transformed into the        *
 *                      destination color.                                                     *
 *                                                                                             *
 *          rgb      -- Reference to the destination RGB color to transform this color into.   *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/02/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
void RGBClass::Adjust(int ratio, RGBClass const & rgb)
{
	/*
	**	Ratio conversion is limited to 0 through 100%. This is
	**	the range of 0 to 255.
	*/
	ratio &= 0x00FF;

	/*
	**	Adjust the color guns by the ratio specified toward the
	**	destination color.
	*/
	int value = (int)rgb.Red - (int)Red;
	Red = (int)Red + (value * ratio) / 256;

	value = (int)rgb.Green - (int)Green;
	Green = (int)Green + (value * ratio) / 256;

	value = (int)rgb.Blue - (int)Blue;
	Blue = (int)Blue + (value * ratio) / 256;
}


/***********************************************************************************************
 * RGBClass::Difference -- Determines the "distance" between two colors.                       *
 *                                                                                             *
 *    This routine is used to calculate a relative distance between two colors. The value is   *
 *    relative only to itself and thus is useful only for determining the magnitude of         *
 *    color difference rather than the nature of the color difference. Palette remapping       *
 *    code uses this routine to find closest matches for colors.                               *
 *                                                                                             *
 * INPUT:   rgb   -- Reference to the color to be compared to this color.                      *
 *                                                                                             *
 * OUTPUT:  Returns the difference between the two colors. The value returned is zero if the   *
 *          colors exactly match. The greater the positive value the greater the difference    *
 *          between the colors.                                                                *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   12/02/1995 JLB : Created.                                                                 *
 *=============================================================================================*/
int RGBClass::Difference(RGBClass const & rgb) const
{
	int r = (int)Red - (int)rgb.Red;
	if (r < 0) r = -r;

	int g = (int)Green - (int)rgb.Green;
	if (g < 0) g = -g;

	int b = (int)Blue - (int)rgb.Blue;
	if (b < 0) b = -b;

	return(r*r + g*g + b*b);
}


/***********************************************************************************************
 * RGBClass::operator HSVClass -- Conversion operator for RGB to HSV object.                   *
 *                                                                                             *
 *    This conversion operator will convert an RGBClass object into an HSVClass object.        *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with a reference (implicit) to the HSVClass object that most closely       *
 *          represents the RGBClass object.                                                    *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/20/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
RGBClass::operator HSVClass (void) const
{
	int hue;
	int saturation;
	int value;

	/*
	**	Fetch working component values for the color guns.
	*/
	int red = Red_Component();
	int green = Green_Component();
	int blue = Blue_Component();

	/*
	**	The hue defaults to none. Only if there is a saturation value will the
	**	hue be calculated.
	*/
	hue = 0;

	/*
	**	Set the value (brightness) to match the brightest color gun.
	*/
	value = (red > green) ? red : green;
	if (blue > value) value = blue;

	/*
	**	Determine the amount of true white present in the color. This is the
	**	minimum color gun value. The white component is used to determine
	**	color saturation.
	*/
	int white = (red < green) ? red : green;
	if (blue < white) white = blue;

	/*
	**	Determine the saturation (intensity) of the color by comparing the
	**	ratio of true white as a component of the overall color. The more
	**	white component, the less saturation.
	*/
	saturation = 0;
	if (value) {
		saturation = ((value - white) * 255) / value;
	}

	/*
	** If there is any saturation at all, then the hue must be calculated. The
	**	hue is based on a six sided color wheel.
	*/
	if (saturation != 0) {
		unsigned int tmp = value - white;
	 	unsigned int r1 = ((value - red) * 255) / tmp;
	 	unsigned int g1 = ((value - green) * 255) / tmp;
	 	unsigned int b1 = ((value - blue) * 255) / tmp;

		// Find effect of second most predominant color.
		// In which section of the hexagon of colors does the color lie?
		if (value == red) {
		 	if (white == green) {
				tmp = 5 * 256 + b1;
			} else {
				tmp = 1 * 256 - g1;
			}
		} else {
			if (value == green) {
			 	if (white == blue) {
					tmp = 1 * 256 + r1;
				} else {
					tmp = 3 * 256 - b1;
				}
			} else {
			 	if (white == red) {
					tmp = 3 * 256 + g1;
				} else {
					tmp = 5 * 256 - r1;
				}
			}
		}

		// Divide by six and round.
		hue = tmp / 6;
	}

	return(HSVClass(hue, saturation, value));
}


/***********************************************************************************************
 * RGBClass::Set -- Set the color index to the RGB object specified.                           *
 *                                                                                             *
 *    This routine will set the specified color index with this RGBClass object. Use this      *
 *    routine to set one color.                                                                *
 *                                                                                             *
 * INPUT:   color -- The color index to set with this RGBClass object.                         *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/20/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void RGBClass::Set(int color) const
{
	Raw_Color_Prep(color);
	Raw_Set();

	((RGBClass &)PaletteClass::CurrentPalette[color]) = *this;
}
