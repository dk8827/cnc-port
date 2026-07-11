/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

//	Bigcheck.h
//	ajw 9/14/98

#ifdef WOLAPI_INTEGRATION

#ifndef BIGCHECKBOX_H
#define BIGCHECKBOX_H

#include	"toggle.h"

#define BIGCHECK_OFFSETX	20
#define BIGCHECK_OFFSETY	0

//***********************************************************************************************
class BigCheckBoxClass : public ToggleClass
{
public:
	BigCheckBoxClass( unsigned id, int x, int y, int w, int h, const char* szCaptionIn, TextPrintType TextFlags, 
							bool bInitiallyChecked = false ) :
		ToggleClass( id, x, y, w, h ),
		TextFlags( TextFlags )
	{
		szCaption = new char[ strlen( szCaptionIn ) + 1 ];
		strcpy( szCaption, szCaptionIn );
		if( bInitiallyChecked )
			Turn_On();
		IsToggleType = 1;
	}
	virtual ~BigCheckBoxClass()
	{
		delete [] szCaption;
	}

	virtual int Draw_Me(int forced=false);
	virtual int Action(unsigned flags, KeyNumType & key);

	bool	Toggle()
	{
		if( IsOn )
		{
			Turn_Off();
			return false;
		}
		Turn_On();
		return true;
	}

protected:
	TextPrintType	TextFlags;
	char*			szCaption;

};

#endif

#endif
