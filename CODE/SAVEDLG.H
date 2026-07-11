/*
**	Command & Conquer(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Header:   F:\projects\c&c\vcs\code\savedlg.h_v   2.14   16 Oct 1995 16:45:12   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               *** 
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : SAVEDLG.H                                                    *
 *                                                                                             *
 *                   Programmer : Maria del Mar McCready Legg, Joe L. Bostic                   *
 *                                                                                             *
 *                   Start Date : Jan 8, 1995                                                  * 
 *                                                                                             *
 *                  Last Update : Jan 18, 1995   [MML]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef SAVEDLG_H
#define SAVEDLG_H

#include "gadget.h"

class SaveOptionsClass 
{
	private:

		enum SaveOptionsClassEnums {
			BUTTON_CANCEL=200,
			BUTTON_SAVE,
			OPTION_WIDTH=216,
			OPTION_HEIGHT=122,
			OPTION_X=((320 - OPTION_WIDTH) / 2) & ~7,
			OPTION_Y=(200 - OPTION_HEIGHT) / 2,
			NUMBER_OF_BUTTONS=2,
			CAPTION_Y_POS=5,
			BORDER1_LEN=49,
			BUTTON_CANCEL_X=90,
			BUTTON_CANCEL_Y=103,
			LISTBOX_X=40,
			LISTBOX_Y=24,
			LISTBOX_W=136,
			LISTBOX_H=72
		};

	public:
		SaveOptionsClass (void) { };
		void Process (void);
};


#endif
