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

/* $Header:   F:\projects\c&c\vcs\code\screen.h_v   2.15   16 Oct 1995 16:47:38   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               *** 
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : SCREEN.H                                                     *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : June 2, 1994                                                 *
 *                                                                                             *
 *                  Last Update : June 2, 1994   [JLB]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef SCREEN_H
#define SCREEN_H


class ScreenClass
{
		/*
		**	The mouse shape is controlled by these variables. These
		**	hold the current mouse shape (so resetting won't be needlessly performed) and
		**	the normal default mouse shape (when arrow shapes are needed).
		*/
		MouseShapeType CurrentMouseShape;
		MouseShapeType NormalMouseShape;

	public:

		ScreenClass(void) {
			CurrentMouseShape = SHP_NONE;
			NormalMouseShape = SHP_MOUSE;
		};
		

		Init(void);
		Set_Default_Mouse(MouseShapeType mouse);
		Force_Mouse_Shape(MouseShapeType mouse);

		unsigned char *GamePalette;
		unsigned char *BlackPalette;
};

#endif
