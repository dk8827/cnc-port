/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef SHAPIPE_H
#define SHAPIPE_H

#include	"pipe.h"
#include	"sha.h"

/*
**	This class serves as a pipe that generates a Secure Hash from the data stream that flows
**	through it. It doesn't modify the data stream in any fashion.
*/
class SHAPipe : public Pipe
{
	public:
		SHAPipe(void) {}
		virtual int Put(void const * source, int slen);

		// Fetch the SHA hash value (stored in result buffer -- 20 bytes long).
		int Result(void * result) const;

	protected:
		SHAEngine SHA;

	private:
		SHAPipe(SHAPipe & rvalue);
		SHAPipe & operator = (SHAPipe const & pipe);
};

#endif
