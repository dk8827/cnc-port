/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RNG_H
#define RNG_H

/*
**	This is an abstract interface class for a random number generator. It serves only to
**	provide random numbers.
*/
class RandomNumberGenerator {
	public:
		virtual ~RandomNumberGenerator() {}

		virtual void Get_Block(void * output, unsigned int size) = 0;
};


#endif

