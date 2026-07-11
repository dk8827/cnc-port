/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef HSV_H
#define HSV_H

class RGBClass;
class HSVClass;

/*
**	Each color entry is represented by this class. It holds the values for the color
**	attributes. The values are recorded in a range from 0 to 255 with 255 being the
**	maximum.
*/
class HSVClass
{
	private:
		static HSVClass const BlackColor;

	public:
		HSVClass(void) : Hue(0), Saturation(0), Value(0) {};
		HSVClass(unsigned char hue, unsigned char saturation, unsigned char value) :
				Hue(hue),
				Saturation(saturation),
				Value(value)
			{};
		operator RGBClass (void) const;

		enum {
			MAX_VALUE=255
		};

		void Adjust(int ratio, HSVClass const & hsv);
		int Difference(HSVClass const & hsv) const;
		int Hue_Component(void) const {return(Hue);};
		int Saturation_Component(void) const {return(Saturation);};
		int Value_Component(void) const {return(Value);};
		void Set(int color) const;

	private:
		unsigned char Hue;
		unsigned char Saturation;
		unsigned char Value;
};

#endif
