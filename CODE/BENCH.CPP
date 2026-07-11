/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"bench.h"
#include	"mpu.h"


/***********************************************************************************************
 * Benchmark::Benchmark -- Constructor for the benchmark object.                               *
 *                                                                                             *
 *    This will construct the benchmark object.                                                *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/18/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
Benchmark::Benchmark(void) :
	Average(0),
	Counter(0),
	TotalCount(0)
{
}


/***********************************************************************************************
 * Benchmark::Reset -- Clear out the benchmark statistics.                                     *
 *                                                                                             *
 *    Use this routine to clear out all the accumulated statistics within this benchmark       *
 *    object. The object is set just as if it was freshly constructed.                         *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/18/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void Benchmark::Reset(void)
{
	Average = 0;
	Counter = 0;
	TotalCount = 0;
}


/***********************************************************************************************
 * Benchmark::Begin -- Start the benchmark operation.                                          *
 *                                                                                             *
 *    Call this routine before the operation to be benchmarked is begun. The corresponding     *
 *    End() function must be called after the operation has completed.                         *
 *                                                                                             *
 * INPUT:   reset -- Should the entire benchmark object be reset at this time as well?         *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The Begin() and End() functions are NOT nestable.                               *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/18/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void Benchmark::Begin(bool reset)
{
	if (reset) Reset();
	Clock = 0;
}


/***********************************************************************************************
 * Benchmark::End -- Mark the end of a benchmarked operation                                   *
 *                                                                                             *
 *    This routine is called at the end of the operation that is being benchmarked. It is      *
 *    important to call this routine as soon as possible after the event being benchmarked     *
 *    has completed.                                                                           *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The Being() and End() functions are NOT nestable.                               *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/18/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void Benchmark::End(void)
{
	unsigned long value = Clock;

	if (Counter == MAXIMUM_EVENT_COUNT) {
		Average -= Average / MAXIMUM_EVENT_COUNT;
		Average += value;
	} else {
		Average += value;
		Counter++;
	}
	TotalCount++;
}


/***********************************************************************************************
 * Benchmark::Value -- Fetch the current average benchmark time.                               *
 *                                                                                             *
 *    This routine will take the statistics already accumulated and determine the average      *
 *    time recorded. This value will be returned.                                              *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the average time that all events tracked by this object.              *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/18/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned long Benchmark::Value(void) const
{
	if (Counter) {
		return(Average / Counter);
	}
	return(0);
}
