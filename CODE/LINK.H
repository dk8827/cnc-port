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

/* $Header:   F:\projects\c&c\vcs\code\link.h_v   2.17   16 Oct 1995 16:45:52   JOE_BOSTIC  $ */
/*********************************************************************************************** 
 ***             C O N F I D E N T I A L  ---  W E S T W O O D   S T U D I O S               *** 
 *********************************************************************************************** 
 *                                                                                             * 
 *                 Project Name : Command & Conquer                                            * 
 *                                                                                             * 
 *                    File Name : LINK.H                                                       * 
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

#ifndef LINK_H
#define LINK_H

/*
**	This implements a simple linked list. It is possible to add, remove, and traverse the
**	list. Since this is a doubly linked list, it is possible to remove an entry from the
**	middle of an existing list.
*/
class LinkClass
{
	public:
		LinkClass(void);
		virtual ~LinkClass(void);

		virtual LinkClass * Get_Next(void) const;
		virtual LinkClass * Get_Prev(void) const;
		virtual LinkClass & Add(LinkClass & object);
		virtual LinkClass & Add_Tail(LinkClass & object);
		virtual LinkClass & Add_Head(LinkClass & object);
		virtual LinkClass const & Head_Of_List(void) const;
		virtual LinkClass & Head_Of_List(void) 
		{
			return (LinkClass &)(((LinkClass const *)this)->Head_Of_List());
		};
		virtual LinkClass const & Tail_Of_List(void) const;
		virtual LinkClass & Tail_Of_List(void)
		{
			return (LinkClass &)(((LinkClass const *)this)->Tail_Of_List());
		};
		virtual void Zap(void);
		virtual LinkClass * Remove(void);

		LinkClass & operator=(LinkClass & link);		// Assignment operator.
		LinkClass(LinkClass & link);						// Copy constructor.

	private:
		/*
		**	Pointers to previous and next link objects in chain.
		*/
		LinkClass * Next;
		LinkClass * Prev;
};

#endif
