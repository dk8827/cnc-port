/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef SHASTRAW_H
#define SHASTRAW_H


#include	"straw.h"
#include	"sha.h"

/*
**	This class serves as a straw that generates a Secure Hash from the data stream that flows
**	through it. It doesn't modify the data stream in any fashion.
*/
class SHAStraw : public Straw
{
	public:
		SHAStraw(void) {}
		virtual int Get(void * source, int slen);

		// Fetch the SHA hash value (stored in result buffer -- 20 bytes long).
		int Result(void * result) const;

	protected:
		SHAEngine SHA;

	private:
		SHAStraw(SHAStraw & rvalue);
		SHAStraw & operator = (SHAStraw const & straw);
};


#endif
