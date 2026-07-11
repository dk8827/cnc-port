/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CRC_H
#define CRC_H

#include	<stdlib.h>
#include	<stdint.h>
#include	<windows.h>

/*
**	The "bool" integral type was defined by the C++ comittee in
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
**	This is a CRC engine class. It will process submitted data and generate a CRC from it.
**	Well, actually, the value returned is not a true CRC. However, it shares the same strength
**	characteristic and is faster to generate than the traditional CRC. This object is treated like
**	a method class. If it is called as a function (using the function operator), it will return
**	the CRC value. There are other function operators to submit data for processing.
*/
class CRCEngine {
	public:

		// Constructor for CRC engine (it can have an override initial CRC value).
		CRCEngine(long initial=0) : CRC((int32_t)initial), Index(0) {
			StagingBuffer.Composite = 0;
		};

		// Fetches CRC value.
		long operator() (void) const {return(Value());};

		// Submits one byte sized datum to the CRC accumulator.
		void operator() (char datum);

		// Submits an arbitrary buffer to the CRC accumulator.
		long operator() (void const * buffer, int length);

		// Implicit conversion operator so this object appears like a 'long integer'.
		operator long(void) const {return(Value());};

	protected:

		bool Buffer_Needs_Data(void) const {
			return(Index != 0);
		};

		long Value(void) const {
			if (Buffer_Needs_Data()) {
				return((int32_t)(Rotate_Left_32((uint32_t)CRC, 1) + (uint32_t)StagingBuffer.Composite));
			}
			return(CRC);
		};

		static uint32_t Rotate_Left_32(uint32_t value, int shift) {
			shift &= 31;
			if (shift == 0) {
				return(value);
			}
			return((value << shift) | (value >> (32 - shift)));
		};

		/*
		**	Current accumulator of the CRC value. This value doesn't take into
		**	consideration any pending data in the staging buffer.
		*/
		int32_t CRC;

		/*
		**	This is the sub index into the staging buffer used to keep track of
		**	partial data blocks as they are submitted to the CRC engine.
		*/
		int Index;

		/*
		**	This is the buffer that holds the incoming partial data. When the buffer
		**	is filled, the value is transformed into the CRC and the buffer is flushed
		**	in preparation for additional data.
		*/
		union {
			int32_t Composite;
			char Buffer[sizeof(int32_t)];
		} StagingBuffer;
};

#endif
