/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

//	ToolTip.h

#ifdef WOLAPI_INTEGRATION

#ifndef TOOLTIP_H
#define TOOLTIP_H

#include "Gadget.h"

#define TOOLTIPTEXT_MAX_LEN		100

#define TOOLTIPDELAY			400		//	Milliseconds

class ToolTipClass
{
public:
	ToolTipClass( GadgetClass* pGadget, const char* szText, int xShow, int yShow, bool bRightAlign = false, bool bIconList = false );
	~ToolTipClass()
	{
		delete [] pSaveRect;
	}

	ToolTipClass*	GetToolTipHit();
	void			Show();
	void			Unshow();
	void			Move( int xShow, int yShow );
	bool			bOverDifferentLine() const;

	ToolTipClass*	next;					//	Next tooltip in list of which *this is a part.

	GadgetClass*	pGadget;							//	Gadget to which this tooltip is bound.

	bool			bRightAlign;

	bool			bShowing;
	bool			bIconList;			//	True if gadget is iconlist and line-specific tooltips are to be used.

protected:
	bool			bGadgetHit() const;

	int				xShow;
	int				yShow;
	int				wShow;
	int				hShow;
	char			szTip[ TOOLTIPTEXT_MAX_LEN + 1 ];	//	Text to show as tip.

	char*			pSaveRect;

	//	Used only if bIconList.
	int				iLastIconListIndex;
	bool			bLastShowNoText;
	int				xLastShow;
	int				yLastShow;
	int				wLastShow;
};

#endif

#endif
