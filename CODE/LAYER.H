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

/* $Header:   F:\projects\c&c\vcs\code\layer.h_v   2.19   16 Oct 1995 16:46:22   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               *** 
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : LAYER.H                                                      *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : May 31, 1994                                                 *
 *                                                                                             *
 *                  Last Update : May 31, 1994   [JLB]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef LAYER_H
#define LAYER_H

#include "vector.h"

class ObjectClass;

class LayerClass : public DynamicVectorClass<ObjectClass *>
{
	public:

		//-----------------------------------------------------------------
		void Sort(void);
		bool Submit(ObjectClass const * object, bool sort=false);
		int Sorted_Add(ObjectClass const * const object);


		virtual void Init(void) {Clear();};
		virtual void One_Time(void) {};

		/*
		**	File I/O.
		*/
		bool Load(FileClass & file);
		bool Save(FileClass & file);
		virtual void Code_Pointers(void);
		virtual void Decode_Pointers(void);
};

#endif
