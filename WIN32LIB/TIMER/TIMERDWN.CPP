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

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Defines /////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Code ////////////////////////////////////////


/***************************************************************************
 * TC::CountDownTimerClass -- Construct a timer class object.              *
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
CountDownTimerClass::CountDownTimerClass(BaseTimerEnum timer, long set, int on)
							:TimerClass(timer, on)
{
	Set(set, on);
}

CountDownTimerClass::CountDownTimerClass(BaseTimerEnum timer, int on)
							:TimerClass(timer, FALSE)
{
	DelayTime = 0;
	if (on) Start();
}


/***************************************************************************
 * CDTC::TIME -- Return the time on the timer.                             *
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
long CountDownTimerClass::Time()
{
	long ticks = DelayTime - TimerClass::Time();

	if (ticks < 0) {
		ticks = 0;
	}
	return(ticks);
}


/***************************************************************************
 * CDTC::SET -- Set the time of a timer.                             		*
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:  ULONG value to set timer at.                                    *
 *                                                                         *
 * OUTPUT:                                                                 *
 *                                                                         *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   07/12/1994 SKB : Created.                                             *
 *=========================================================================*/
long CountDownTimerClass::Set(long value, BOOL start)
{
	DelayTime = value;
	TimerClass::Reset(start);
	return(Time());
}



