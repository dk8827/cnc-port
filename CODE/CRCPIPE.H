/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CRCPIPE_H
#define CRCPIPE_H

#include	"pipe.h"
#include	"crc.h"

/*
**	This class doesn't modify the data being piped through, but it does examine it and build
**	a CRC value from the data.
*/
class CRCPipe : public Pipe
{
	public:
		CRCPipe(void) {}
		virtual int Put(void const * source, int slen);

		// Fetch the CRC value.
		long Result(void) const;

	protected:
		CRCEngine CRC;

	private:
		CRCPipe(CRCPipe & rvalue);
		CRCPipe & operator = (CRCPipe const & pipe);
};

#endif
