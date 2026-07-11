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

/* $Header:   F:\projects\c&c\vcs\code\factory.h_v   2.17   16 Oct 1995 16:45:44   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : FACTORY.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 12/26/94                                                     *
 *                                                                                             *
 *                  Last Update : December 26, 1994 [JLB]                                      *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef FACTORY_H
#define FACTORY_H

#include	"stage.h"

class FactoryClass : private StageClass
{
	public:
		FactoryClass(void);
		~FactoryClass(void);
		static void * operator new(size_t size);
		static void operator delete(void *ptr);

		static void Init(void);

		/*
		**	File I/O.
		*/
		bool  Load(FileClass & file);
		bool  Save(FileClass & file);
		void  Code_Pointers(void);
		void  Decode_Pointers(void);

		bool  Abandon(void);
		bool  Completed(void);
		bool  Has_Changed(void);
		bool  Has_Completed(void);
		bool  Is_Building(void) const {return(Fetch_Rate() != 0);};
		bool  Set(TechnoTypeClass const & object, HouseClass & house);
		bool  Set(int const & type, HouseClass & house);
		bool  Start(void);
		bool  Suspend(void);
		int  Completion(void);
		TechnoClass *  Get_Object(void) const;
		int  Get_Special_Item(void) const;
		void  AI(void);
		void  Set(TechnoClass & object);
		HouseClass *  Get_House(void) {return(House);};

		/*
		**	Dee-buggin' support.
		*/
		int Validate(void) const;

		/*
		**	This flag is used to maintain the pool of factory class objects. If the object has
		**	been allocated, then this flag is true. Otherwise, the object is free to be
		**	allocated.
		*/
		unsigned IsActive:1;

	protected:
		enum StepCountEnum {
			STEP_COUNT=108			// Number of steps to break production down into.
		};

		int Cost_Per_Tick(void);

	private:

		/*
		**	If production is temporarily suspended, then this flag will be true. A factory
		**	is suspended when it is first created, when production has completed, and when
		**	explicitly instructed to Suspend() production. Suspended production is not
		**	abandoned. It may be resumed with a call to Start().
		*/
		unsigned IsSuspended:1;

		/*
		**	If the AI process detected that the production process has advanced far enough
		**	that a change in the building animation would occur, this flag will be true.
		**	Examination of this flag (through the Has_Chaged function) allows intelligent
		**	updating of any production graphic.
		*/
		unsigned IsDifferent:1;

		/*
		**	This records the balance due on the current production item. This value will
		**	be reduced as production proceeds. It will reach zero the moment production has
		**	finished. Using this method ensures that the total production cost will be EXACT
		**	regardless of the number of installment payments that are made.
		*/
		int Balance;
		int OriginalBalance;

		/*
		**	This is the object that is being produced. It is held in a state of limbo while
		**	undergoing production. Since the object is created at the time production is
		**	started, it is always available when production completes.
		*/
		TechnoClass * Object;

		/*
		**	If the factory is not producing an object and is instead producing
		** a special item, then special item will be set.
		*/
		int SpecialItem;

		/*
		** The factory has to be doing production for one house or another.
		** The house pointer will point to whichever house it is being done
		** for.
		*/
		HouseClass  * House;
};

#endif
