/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "font.h"
#include <wwstd.h>



/***************************************************************************
 * SET_FONT -- Changes the default text printing font.                     *
 *                                                                         *
 *    This routine will change the default text printing font for all      *
 *    text output.  It handles updating the system where necessary.        *
 *                                                                         *
 * INPUT:   fontptr  -- Pointer to the font to change to.                  *
 *                                                                         *
 * OUTPUT:  Returns with a pointer to the previous font.                   *
 *                                                                         *
 * WARNINGS:   none                                                        *
 *                                                                         *
 * HISTORY:                                                                *
 *   09/06/1991 JLB : Created.                                             *
 *   09/17/1991 JLB : Fixed return value bug.                              *
 *   01/31/1992 DRD : Modified to use new font format.                     *
 *   06/29/1994 SKB : modified for 32 bit library                          *
 *=========================================================================*/
void * __cdecl Set_Font(void const *fontptr)
{
	void *oldfont;
	char	const *blockptr;

	oldfont = (void *) FontPtr;

	if (fontptr) {
		FontPtr    = (void *) fontptr;

		/*
		**	Inform the system about the new font.
		*/

		FontWidthBlockPtr = (char*)fontptr + *(unsigned short *)((char*)fontptr + FONTWIDTHBLOCK);
		blockptr  = (char*)fontptr + *(unsigned short *)((char*)fontptr + FONTINFOBLOCK);
		FontHeight = *(blockptr + FONTINFOMAXHEIGHT);
		FontWidth  = *(blockptr + FONTINFOMAXWIDTH);
		//Draw_Char_Setup();

#if FALSE
		WindowLines = WinH / FontHeight;
		WindowWidth = WinW << 3;
		WindowColumns = WindowWidth / FontWidth;
#endif
	}

	return(oldfont);
}
