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

/* $Header:   F:\projects\c&c\vcs\code\shapebtn.h_v   2.18   16 Oct 1995 16:46:30   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***             C O N F I D E N T I A L  ---  W E S T W O O D   S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : SHAPEBTN.H                                                   *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 01/15/95                                                     *
 *                                                                                             *
 *                  Last Update : January 15, 1995 [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef SHAPEBTN_H
#define SHAPEBTN_H

#include	"toggle.h"

class ShapeButtonClass : public ToggleClass
{
	public:
		ShapeButtonClass(void);
		ShapeButtonClass(unsigned id, void const * shapes, int x, int y);
		virtual int Draw_Me(int forced=false);
		virtual void Set_Shape(void const * data);

		enum ShapeButtonClassEnums {
			UP_SHAPE,				// Shape to use when button is "up".
			DOWN_SHAPE,				// Shape to use when button is "down".
			DISABLED_SHAPE,		// Shape to use when button is disabled.
		};

		unsigned ReflectButtonState:1;

	protected:

		/*
		**	This points to the shape data file. This file contains the appropriate shapes
		**	for this button in the offsets specified above.
		*/
		void const * ShapeData;
};
#endif
