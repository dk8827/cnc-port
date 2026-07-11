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

/* $Header:   F:\projects\c&c\vcs\code\credits.h_v   2.18   16 Oct 1995 16:47:26   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               *** 
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : CREDIT.H                                                     *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : April 19, 1994                                               *
 *                                                                                             *
 *                  Last Update : April 19, 1994   [JLB]                                       *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef CREDITS_H
#define CREDITS_H

/****************************************************************************
**	The animating credit counter display is controlled by this class.
*/
class CreditClass {
	public:
		long Credits;		// Value of credits trying to update display to.

		/*---------------------------------------------------------------------
		**	Constructors, Destructors, and overloaded operators.
		*/
		CreditClass(void);

		/*---------------------------------------------------------------------
		**	Member function prototypes.
		*/
		void Update(bool forced=false, bool redraw=false);

		void Graphic_Logic(bool forced=false);
		void AI(bool forced=false);

		long	Current;		// Credit value currently displayed.

		unsigned IsToRedraw:1;
		unsigned IsUp:1;
		unsigned IsAudible:1;

	private:
		int	Countdown;	// Delay between ticks.
};

#endif

