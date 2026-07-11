/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include <wwstd.h>
#include "timer.H"
#include <stdio.h>
#include <stdlib.h>


/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Code ////////////////////////////////////////

/***************************************************************************
 * TC::TIMERCLASS -- Construct a timer class object.                       *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/12/1994 SKB : Created.                                             *
 *=========================================================================*/
TimerClass::TimerClass(BaseTimerEnum timer, BOOL on)
{
	Accumulated = 0;
	Started = 0;

	TickType=timer;

	if (on && TimerSystemOn) Start();
}




/***********************************************************************************************
 * TC:Get_Ticks -- return the number of ticks on the system or user timers                     *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   tick count                                                                        *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *              10/5/95 4:17PM ST : Created                                                    *
 *=============================================================================================*/

long TimerClass::Get_Ticks ( void )

{
	if ( WindowsTimer ){
		switch ( TickType ){

		 	case BT_SYSTEM :
				return ( WindowsTimer->Get_System_Tick_Count() );

		 	case BT_USER :
				return ( WindowsTimer->Get_User_Tick_Count() );

		}
	}
	return 0;
}



/***************************************************************************
 * TIMERCLASS::TIME -- Get the current time of timer.                      *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/03/1995 SKB : Created.                                             *
 *=========================================================================*/
long TimerClass::Time(void)
{
	if (Started) {
		long ticks = Get_Ticks();
		Accumulated += ticks - (Started-1);
		Started = ticks+1;
	}
	return(Accumulated);
}


/***************************************************************************
 * TC::STOP -- Stop the timer.                                             *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/12/1994 SKB : Created.                                             *
 *=========================================================================*/
long TimerClass::Stop(void)
{
	long time = Time();
	Started = 0;
	return(time);
}


/***************************************************************************
 * TC::START -- Start a timer.                                             *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/12/1994 SKB : Created.                                             *
 *=========================================================================*/
long TimerClass::Start(void)
{
	if (!Started) {
		Started = Get_Ticks()+1;
	}
	return(Time());
}


/***************************************************************************
 * TC::SET -- Set the time of a timer.                                     *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:  long value to set timer at.                                     *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/12/1994 SKB : Created.                                             *
 *   05/03/1995 SKB : If start return Start since it returns Time          *
 *=========================================================================*/
long TimerClass::Set(long value, BOOL start)
{
	Started = 0;
	Accumulated = value;
	if (start) return (Start());
	return(Time());
}