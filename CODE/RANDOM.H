/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RANDOM_H
#define RANDOM_H

/**********************************************************************
** Enable this define to turn on the random # counters.  This must not
** be defined for the release version, or saved games won't work!
*/
//#define RANDOM_COUNT


/*
**	This class functions like a 'magic' int value that returns a random number
**	every time it is read. To set the "random seed" for this, just assign a number
**	to the object (just as you would if it were a true 'int' value). Take note that although
**	this class will return an 'int', the actual significance of the random number is
**	limited to 15 bits (0..32767).
*/
class RandomClass {
	public:
		RandomClass(unsigned seed=0);

		operator int(void) {return(operator()());};
		int operator() (void);
		int operator() (int minval, int maxval);

		enum {
			SIGNIFICANT_BITS=15				// Random number bit significance.
		};

		unsigned long Seed;

#ifdef RANDOM_COUNT
		unsigned long Count1;
		unsigned long Count2;
#endif

	protected:
		/*
		**	Internal working constants that are used to generate the next
		**	random number.
		*/
		enum {
			MULT_CONSTANT=0x41C64E6D,		// K multiplier value.
			ADD_CONSTANT=0x00003039,		// K additive value.
			THROW_AWAY_BITS=10				// Low bits to throw away.
		};
};

#endif
