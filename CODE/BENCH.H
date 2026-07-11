/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BENCH_H
#define BENCH_H

#include	"mpu.h"
#include	"ftimer.h"

/*
**	The "bool" integral type was defined by the C++ committee in
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

/*
**	This is a timer access object that will fetch the internal Pentium
**	clock value.
*/
class PentiumTimerClass
{
	public:
		unsigned long operator () (void) const {unsigned long h;unsigned long l = Get_CPU_Clock(h);return((l >> 4) | (h << 28));}
		operator unsigned long (void) const {unsigned long h;unsigned long l = Get_CPU_Clock(h);return((l >> 4) | (h << 28));}
};


/*
**	A performance tracking tool object. It is used to track elapsed time. Unlike a simple clock, this
**	class will keep a running average of the duration. Typical use of this would be to benchmark some
**	process that occurs multiple times. By benchmarking an average time, inconsistencies in a particular
**	run can be overcome.
*/
class Benchmark
{
	public:
		Benchmark(void);

		void Begin(bool reset=false);
		void End(void);

		void Reset(void);
		unsigned long Value(void) const;
		unsigned long Count(void) const {return(TotalCount);}

	private:
		/*
		**	The maximum number of events to keep running average of. If
		**	events exceed this number, then older events drop off the
		**	accumulated time. This number needs to be as small as
		**	is reasonable. The larger this number gets, the less magnitude
		**	that the benchmark timer can handle. Example; At a value of
		**	256, the magnitude of the timer can only be 24 bits.
		*/
		enum {MAXIMUM_EVENT_COUNT=256};

		/*
		**	This is the timer the is used to clock the events.
		*/
		BasicTimerClass<PentiumTimerClass> Clock;

		/*
		**	The total time off all events tracked so far.
		*/
		unsigned long Average;

		/*
		**	The total number of events tracked so far.
		*/
		unsigned long Counter;

		/*
		**	Absolute total number of events (possibly greater than the
		**	number of events tracked in the average).
		*/
		unsigned long TotalCount;
};


#endif
