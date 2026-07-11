/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BLOWPIPE_H
#define BLOWPIPE_H

#include	"pipe.h"
#include	"blowfish.h"

/*
**	Performs Blowfish encryption/decryption on the data stream that is piped
**	through this class.
*/
class BlowPipe : public Pipe
{
	public:
		typedef enum CryptControl {
			ENCRYPT,
			DECRYPT
		} CryptControl;

		BlowPipe(CryptControl control) : BF(NULL), Counter(0), Control(control) {}
		virtual ~BlowPipe(void) {delete BF;BF = NULL;}
		virtual int Flush(void);

		virtual int Put(void const * source, int slen);

		// Submit key for blowfish engine.
		void Key(void const * key, int length);

	protected:
		/*
		**	The Blowfish engine used for encryption/decryption. If this pointer is
		**	NULL, then this indicates that the blowfish engine is not active and no
		**	key has been submitted. All data would pass through this pipe unchanged
		**	in that case.
		*/
		BlowfishEngine * BF;

	private:
		char Buffer[8];
		int Counter;
		CryptControl Control;

		BlowPipe(BlowPipe & rvalue);
		BlowPipe & operator = (BlowPipe const & pipe);
};


#endif
