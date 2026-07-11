/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef PK_H
#define PK_H

#include	"int.h"

/*
**	This class holds a public or private key used in Public Key Cryptography. It also serves
**	as the conduit for encrypting/decrypting data using that key. Cryptography, using this
**	method, has a couple of characteristics that affect how it is used. One, the process of
**	encrypting/decrypting is very slow. This limits the effective quantity of data that can
**	be processed. Two, the ciphertext is larger than the plaintext. This property generally
**	limits its use to streaming data as opposed to random access data. The data is processed
**	in blocks. The size of the ciphertext and plaintext blocks can be determined only from
**	the key itself.
**
**	A reasonable use of this technology would be to encrypt only critical data such as the
**	password for a fast general purpose cryptographic algorithm.
*/
class PKey
{
	public:
		PKey(void) : Modulus(0), Exponent(0), BitPrecision(0) {}
		PKey(void const * exponent, void const * modulus);		// DER initialization.

		int Encrypt(void const * source, int slen, void * dest) const;
		int Decrypt(void const * source, int slen, void * dest) const;

		static void Generate(Straw & random, int bits, PKey & fastkey, PKey & slowkey);

		int Plain_Block_Size(void) const {return((BitPrecision-1)/8);}
		int Crypt_Block_Size(void) const {return(Plain_Block_Size()+1);}
		int Block_Count(int plaintext_length) const {return((((plaintext_length-1)/Plain_Block_Size())+1));}

		int Encode_Modulus(void * buffer) const;
		int Encode_Exponent(void * buffer) const;

		void Decode_Modulus(void * buffer);
		void Decode_Exponent(void * buffer);

		static long Fast_Exponent(void) {return(65537L);}

	private:

		// p*q
		BigInt Modulus;

		// 65537 or
		// inverse of (p-1)(q-1).
		BigInt Exponent;

		// Maximum bits allowed for block.
		int BitPrecision;
};


#endif
