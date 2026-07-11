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

/* $Header:   F:\projects\c&c\vcs\code\fly.h_v   2.19   16 Oct 1995 16:45:18   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : FLY.H                                                        *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : April 24, 1994                                               *
 *                                                                                             *
 *                  Last Update : April 24, 1994   [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef FLY_H
#define FLY_H

typedef enum ImpactType {
	IMPACT_NONE,		// No movement (of significance) occurred.
	IMPACT_NORMAL,		// Some (non eventful) movement occurred.
	IMPACT_EDGE			// The edge of the world was reached.
} ImpactType;


/****************************************************************************
**	Flying objects are handled by this class definition.
*/
class FlyClass {
	public:
		/*---------------------------------------------------------------------
		**	Constructors, Destructors, and overloaded operators.
		*/
		FlyClass(void) {
			SpeedAdd = MPH_IMMOBILE;
			SpeedAccum = 0;
		};

		/*---------------------------------------------------------------------
		**	Member function prototypes.
		*/
		void Fly_Speed(int speed, MPHType maximum);
		ImpactType Physics(COORDINATE &coord, DirType facing);
		MPHType Get_Speed(void) const {return(SpeedAdd);};

		/*
		**	File I/O.
		*/
		void Code_Pointers(void);
		void Decode_Pointers(void);

	private:
		/*
		**	Object movement consists of incrementing the accumulator until enough "distance"
		**	has accumulated so that moving the object becomes reasonable.
		*/
		unsigned SpeedAccum;			// Lepton accumulator.
		MPHType SpeedAdd;			// Lepton add (per frame).
};

#endif
