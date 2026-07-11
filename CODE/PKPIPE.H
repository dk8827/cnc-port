/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef PKPIPE_H
#define PKPIPE_H

#include	"pipe.h"
#include	"pk.h"
#include "rndstraw.h"
#include	"blowpipe.h"


/*
**	This pipe will encrypt/decrypt the data stream. The data is encrypted by generating a
**	symetric key that is then encrypted using the public key system. This symetric key is then
**	used to encrypt the remaining data.
*/
class PKPipe : public Pipe
{
	public:
		typedef enum CryptControl {
			ENCRYPT,
			DECRYPT
		} CryptControl;

		PKPipe(CryptControl control, RandomStraw & rnd);

		virtual void Put_To(Pipe * pipe);
		virtual void Put_To(Pipe & pipe) {Put_To(&pipe);}

		// Feed data through for processing.
		virtual int Put(void const * source, int length);

		// Submit key for encryption/decryption.
		void Key(PKey const * key);

	private:
		enum {
			BLOWFISH_KEY_SIZE=BlowfishEngine::MAX_KEY_LENGTH,
			MAX_KEY_BLOCK_SIZE=256		// Maximum size of pk encrypted blowfish key.
		};

		/*
		**	This flag indicates whether the PK (fetch blowfish key) phase is
		**	in progress or not.
		*/
		bool IsGettingKey;

		/*
		**	This is the random straw that is needed to generate the
		**	blowfish key.
		*/
		RandomStraw & Rand;

		/*
		**	This is the attached blowfish pipe. After the blowfish key has been
		**	decrypted, then the PK processor goes dormant and the blowfish processor
		**	takes over the data flow.
		*/
		BlowPipe BF;

		/*
		**	Controls the method of processing the data stream.
		*/
		CryptControl Control;

		/*
		**	Pointer to the key to use for encryption/decryption. The actual process
		**	performed is controlled by the Control member. A key can be used for
		**	either encryption or decryption -- it makes no difference. However, whichever
		**	process is performed, the opposite process must be performed using the
		**	other key.
		*/
		PKey const * CipherKey;

		/*
		**	This is the staging buffer for the block of data. This block must be as large as
		**	the largest possible key size or the largest blowfish key (whichever is greater).
		*/
		char Buffer[MAX_KEY_BLOCK_SIZE];

		/*
		**	The working counter that holds the number of bytes in the staging buffer.
		*/
		int Counter;

		/*
		**	This records the number of bytes remaining in the current block. This
		**	will be the number of bytes left to accumulate before the block can be
		**	processed either for encryption or decryption.
		*/
		int BytesLeft;

		int Encrypted_Key_Length(void) const;
		int Plain_Key_Length(void) const;

		PKPipe(PKPipe & rvalue);
		PKPipe & operator = (PKPipe const & pipe);
};


#endif
