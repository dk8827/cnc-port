/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BLWSTRAW_H
#define BLWSTRAW_H

#include	"straw.h"
#include	"blowfish.h"


/*
**	Performs Blowfish encryption/decryption to the data that is drawn through this straw. The
**	process is controlled by the key which must be submitted to the class before any data
**	manipulation will occur. The Blowfish algorithm is symmetric, thus the same key is used
**	for encryption as is for decryption.
*/
class BlowStraw : public Straw
{
	public:
		typedef enum CryptControl {
			ENCRYPT,
			DECRYPT
		} CryptControl;

		BlowStraw(CryptControl control) : BF(NULL), Counter(0), Control(control) {}
		virtual ~BlowStraw(void) {delete BF;BF = NULL;}

		virtual int Get(void * source, int slen);

		// Submit key for blowfish engine.
		void Key(void const * key, int length);

	protected:
		/*
		**	The Blowfish engine used for encryption/decryption. If this pointer is
		**	NULL, then this indicates that the blowfish engine is not active and no
		**	key has been submitted. All data would pass through this straw unchanged
		**	in that case.
		*/
		BlowfishEngine * BF;

	private:
		char Buffer[8];
		int Counter;
		CryptControl Control;

		BlowStraw(BlowStraw & rvalue);
		BlowStraw & operator = (BlowStraw const & straw);
};


#endif
