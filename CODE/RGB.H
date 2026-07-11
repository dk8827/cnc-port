/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RGB_H
#define RGB_H

class PaletteClass;
class HSVClass;

extern "C" void __cdecl Set_Palette_Range(void *palette);

#ifndef OUTPORTB
#define OUTPORTB
extern void outportb(int port, unsigned char data);
#pragma aux outportb parm [edx] [al] =		\
		"out	dx,al"

extern void outport(int port, unsigned short data);
#pragma aux outport parm [edx] [ax] =		\
		"out	dx,al"		\
		"inc	dx"			\
		"mov	al,ah"		\
		"out	dx,al"
#endif

extern void outrgb(unsigned char red, unsigned char green, unsigned char blue);
#pragma aux outrgb parm [al] [bl] [cl] \
		modify [dx al] = \
		"mov	dx,03C9h"	\
		"out	dx,al"		\
		"jmp	e1"			\
		"e1:"					\
		"mov	al,bl" 		\
		"out	dx,al"		\
		"jmp	e2"			\
		"e2:" 				\
		"mov	al,cl" 		\
		"out	dx,al"		\
		"jmp	e3"			\
		"e3:"

/*
**	Each color entry is represented by this class. It holds the values for the color
**	guns. The gun values are recorded in device dependant format, but the interface
**	uses gun values from 0 to 255.
*/
class RGBClass
{
//	static RGBClass const BlackColor;

	public:
		RGBClass(void) : Red(0), Green(0), Blue(0) {};
		RGBClass(unsigned char red, unsigned char green, unsigned char blue) :
				Red((unsigned char)(red>>2)),
				Green((unsigned char)(green>>2)),
				Blue((unsigned char)(blue>>2))
			{};
		operator HSVClass (void) const;
		RGBClass & operator = (RGBClass const & rgb) {
			if (this == &rgb) return(*this);

			Red = rgb.Red;
			Green = rgb.Green;
			Blue = rgb.Blue;
			return(*this);
		};

		enum {
			MAX_VALUE=255
		};

		void Adjust(int ratio, RGBClass const & rgb);
//		void Adjust(int ratio, RGBClass const & rgb = BlackColor);
		int Difference(RGBClass const & rgb) const;
		int Red_Component(void) const {return ((Red << 2) | (Red >> 6));};
		int Green_Component(void) const {return((Green << 2) | (Green >> 6));};
		int Blue_Component(void) const {return((Blue << 2) | (Blue >> 6));};
		void Set(int color) const;

	private:

		friend class PaletteClass;

		void Raw_Set(void) const {
			outrgb(Red, Green, Blue);
//			outportb(0x03C9, Red);
//			outportb(0x03C9, Green);
//			outportb(0x03C9, Blue);
		};

		static void Raw_Color_Prep(unsigned char color) {
			outportb(0x03C8, color);
		};

		/*
		**	These hold the actual color gun values in machine dependant scale. This
		**	means the values range from 0 to 63.
		*/
		unsigned char Red;
		unsigned char Green;
		unsigned char Blue;
};

class PaletteClass
{
	public:
		enum {
			COLOR_COUNT=256
		};

		PaletteClass(void) {
			for (int index = 0; index < COLOR_COUNT; index++) {
				Colors[index] = RGBClass();
			}
		};

		PaletteClass(RGBClass const & rgb) {
			for (int index = 0; index < COLOR_COUNT; index++) {
				Colors[index] = rgb;
			}
		};

		RGBClass & operator [] (int index) {return(Colors[index]);};
		RGBClass const & operator [] (int index) const {return(Colors[index]);};
		operator void * (void) {return((void *)Colors);};
		operator void const * (void) const {return((void const *)Colors);};
		operator unsigned char * (void) {return((unsigned char *)Colors);};
		operator unsigned char const * (void) const {return((unsigned char const *)Colors);};
		operator bool (void) const {return(true);};
		bool operator ! (void) const {return(false);};

		int Closest_Color(RGBClass const & rgb) const {
			int best = 0;
			int bestdiff = Colors[0].Difference(rgb);

			for (int index = 1; index < COLOR_COUNT; index++) {
				int diff = Colors[index].Difference(rgb);
				if (diff < bestdiff) {
					best = index;
					bestdiff = diff;
				}
			}
			return(best);
		};

		void Adjust(int ratio) {
			for (int index = 0; index < COLOR_COUNT; index++) {
				Colors[index].Adjust(ratio, RGBClass());
			}
		};

		void Adjust(int ratio, PaletteClass const & palette) {
			for (int index = 0; index < COLOR_COUNT; index++) {
				Colors[index].Adjust(ratio, palette[index]);
			}
		};

		void Adjust(PaletteClass const & palette, int ratio) {
			Adjust(ratio, palette);
		};

		void Partial_Adjust(int ratio, PaletteClass const & palette, unsigned char const * lut) {
			for (int index = 0; index < COLOR_COUNT; index++) {
				if (lut[index]) {
					Colors[index].Adjust(ratio, palette[index]);
				}
			}
		};

		void Partial_Adjust(int ratio, PaletteClass const & palette, char const * lut) {
			Partial_Adjust(ratio, palette, (unsigned char const *)lut);
		};

		void Partial_Adjust(int ratio, unsigned char const * lut) {
			for (int index = 0; index < COLOR_COUNT; index++) {
				if (lut[index]) {
					Colors[index].Adjust(ratio, RGBClass());
				}
			}
		};

		void Partial_Adjust(int ratio, char const * lut) {
			Partial_Adjust(ratio, (unsigned char const *)lut);
		};

		void Set(int delay=0, void (*callback)(void)=0) const {
			(void)delay;
			CurrentPalette = *this;
			Set_Palette_Range((void *)Colors);
			if (callback) {
				callback();
			}
		};

		static PaletteClass CurrentPalette;

	private:
		RGBClass Colors[COLOR_COUNT];
};

extern RGBClass const BlackColor;

#endif
