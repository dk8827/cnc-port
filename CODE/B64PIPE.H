/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef B64PIPE_H
#define B64PIPE_H

#include	"pipe.h"

/*
**	This class performs Base64 encoding/decoding to the data that is piped through. Note that
**	encoded data will grow in size by about 30%. The reverse occurs when decoding.
*/
class Base64Pipe : public Pipe
{
	public:
		typedef enum CodeControl {
			ENCODE,
			DECODE
		} CodeControl;

		Base64Pipe(CodeControl control) : Control(control), Counter(0) {}

		virtual int Flush(void);
		virtual int Put(void const * source, int slen);

	private:

		/*
		**	Indicates if this is for encoding or decoding of Base64 data.
		*/
		CodeControl Control;

		/*
		**	The counter of the number of accumulated bytes pending for processing.
		*/
		int Counter;

		/*
		**	Buffer that holds the Base64 coded bytes. This will be the staging buffer if
		**	this is for a decoding process. Otherwise, it will be used as a scratch buffer.
		*/
		char CBuffer[4];

		/*
		**	Buffer that holds the plain bytes. This will be the staging buffer if this
		**	is for an encoding process. Otherwise, it will be used as a scratch buffer.
		*/
		char PBuffer[3];

		/*
		**	Explicitly disable the copy constructor and the assignment operator.
		*/
		Base64Pipe(Base64Pipe & rvalue);
		Base64Pipe & operator = (Base64Pipe const & pipe);
};

#endif
