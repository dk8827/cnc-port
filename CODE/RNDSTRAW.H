/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RNDSTRAW_H
#define RNDSTRAW_H


#include	"straw.h"
#include	"random.h"

/*
**	This is a straw terminator class. It will generate random numbers to fill the data request.
**	Unlike regular straw terminators, this class will never run out of "data".
*/
class RandomStraw : public Straw
{
	public:
		RandomStraw(void);
		virtual ~RandomStraw(void);

		virtual int Get(void * source, int slen);

		void Reset(void);
		void Seed_Bit(int seed);
		void Seed_Byte(char seed);
		void Seed_Short(short seed);
		void Seed_Long(long seed);

		int Seed_Bits_Needed(void) const;

	private:
		/*
		**	Counter of the number of seed bits stored to this random number
		**	generator.
		*/
		int SeedBits;

		/*
		**	The current random generator to use when fetching the next random
		**	byte of data.
		*/
		int Current;

		/*
		**	Array of generators. There must be at least 448 bits of random number seed
		**	in order to be reasonably secure, however, using 1024 bits would be best.
		*/
		RandomClass Random[32];

		void Scramble_Seed(void);

		RandomStraw(RandomStraw & rvalue);
		RandomStraw & operator = (RandomStraw const & pipe);
};


#endif
