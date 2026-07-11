/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef STATBTN_H
#define STATBTN_H

#include	"gadget.h"
#include	"buff.h"

class StaticButtonClass : public GadgetClass
{
	public:
		StaticButtonClass(void);
		StaticButtonClass(unsigned id, char const * text, TextPrintType style, int x, int y, int w=-1, int h=-1);
		virtual int Draw_Me(int forced=false);
		virtual void Set_Text(char const * text, bool resize = false);

	protected:

		virtual void Draw_Background(void);
		virtual void Draw_Text(char const * text);

		/*
		**	If a background is to be preserved for this button, then this will point to
		**	a buffer that holds a pristine background image.
		*/
		Buffer Background;

		/*
		**	This points to a copy of the string that is used for the button's text.
		*/
		char * String;

		/*
		**	This is the print flags to use when rendering this button's text.
		*/
		TextPrintType PrintFlags;
};

#endif

