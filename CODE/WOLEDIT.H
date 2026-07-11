/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifdef WOLAPI_INTEGRATION

/***************************************************************************
 * WOLEditClass -- Derived from EditClass, includes changes I wanted for
 *                 wolapi integration stuff.
 *
 * HISTORY:    07/17/1998 ajw : Created.
 *=========================================================================*/

#include "Function.h"

class WOLEditClass : public EditClass
{
public:
	WOLEditClass(int id, char * text, int max_len, TextPrintType flags, int x, int y, int w, int h, EditStyle style) :
		EditClass( id, text, max_len, flags, x, y, w, h, style )	{}
		
	virtual int Action (unsigned flags, KeyNumType &key);		//	Override of base

protected:
	virtual void Draw_Text( char const * text );				//	Override of base

};

#endif
