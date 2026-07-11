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

/* $Header:   F:\projects\c&c\vcs\code\abstract.h_v   2.20   16 Oct 1995 16:46:30   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : ABSTRACT.H                                                   *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 01/26/95                                                     *
 *                                                                                             *
 *                  Last Update : January 26, 1995 [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef ABSTRACT_H
#define ABSTRACT_H

DirType  Direction(CELL cell1, CELL cell2);
DirType  Direction(COORDINATE coord1, COORDINATE coord2);
int  Distance(COORDINATE coord1, COORDINATE coord2);
int  Distance(CELL coord1, CELL coord2);
COORDINATE  As_Coord(TARGET target);

class AbstractTypeClass;

class AbstractClass
{
	public:

		/*
		**	The coordinate location of the unit. For vehicles, this is the center
		**	point. For buildings, it is the upper left corner.
		*/
		COORDINATE Coord;

		/*
		**	The actual object ram-space is located in arrays in the data segment. This flag
		**	is used to indicate which objects are free to be reused and which are currently
		**	in use by the game.
		*/
		unsigned IsActive:1;

		/*-----------------------------------------------------------------------------------
		**	Constructor & destructors.
		*/
		AbstractClass(void) {Coord = 0L;};
		virtual ~AbstractClass(void) {};

		/*
		**	Query functions.
		*/
		virtual HousesType Owner(void) const {return HOUSE_NONE;};

		/*
		**	Coordinate query support functions.
		*/
		virtual COORDINATE Center_Coord(void) const {return Coord;};
		virtual COORDINATE Target_Coord(void) const {return Coord;};

		/*
		**	Coordinate inquiry functions. These are used for both display and
		**	combat purposes.
		*/
		DirType Direction(AbstractClass const * object) const {return ::Direction(Center_Coord(), object->Target_Coord());};
		DirType Direction(COORDINATE coord) const {return ::Direction(Center_Coord(), coord);};
		DirType Direction(TARGET target) const {return ::Direction(Center_Coord(), As_Coord(target));};
		DirType Direction(CELL cell) const {return ::Direction(Coord_Cell(Center_Coord()), cell);};
		int Distance(TARGET target) const;
		int Distance(COORDINATE coord) const {return ::Distance(Center_Coord(), coord);};
		int Distance(CELL cell) const {return ::Distance(Coord_Cell(Center_Coord()), cell);};
		int Distance(AbstractClass const * object) const {return ::Distance(Center_Coord(), object->Target_Coord());};

		/*
		**	Object entry and exit from the game system.
		*/
		virtual MoveType Can_Enter_Cell(CELL , FacingType = FACING_NONE) const {return MOVE_OK;};

		/*
		**	AI.
		*/
		virtual void AI(void) {};

};


#endif
