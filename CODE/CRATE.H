/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CRATE_H
#define CRATE_H

#include	"ftimer.h"
#include	"jshell.h"


/*
**	The "bool" integral type was defined by the C++ comittee in
**	November of '94. Until the compiler supports this, use the following
**	definition.
*/
#ifndef __BORLANDC__
#ifndef TRUE_FALSE_DEFINED
#define TRUE_FALSE_DEFINED
enum {false=0,true=1};
typedef int bool;
#endif
#endif

class CrateClass {
	public:
		CrateClass(void) : Timer(NoInitClass()), Cell(-1) {}
		void Init(void) {Make_Invalid();}
		bool Create_Crate(CELL cell);
		bool Is_Here(CELL cell) const {return(Is_Valid() && cell == Cell);}
		bool Remove_It(void);
		bool Is_Expired(void) const {return(Is_Valid() && Timer == 0);}
		bool Is_Valid(void) const {return(Cell != -1);}

	private:
		static bool Put_Crate(CELL & cell);
		static bool Get_Crate(CELL cell);

		void Make_Invalid(void) {Cell = -1;Timer.Stop();}

		CDTimerClass<FrameTimerClass> Timer;
		CELL Cell;
};


#endif
