/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BLOWFISH_H
#define BLOWFISH_H

#include	<limits.h>
#include	<stdint.h>


/*
**	The "bool" integral type was defined by the C++ committee in
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
**	This engine will process data blocks by encryption and decryption.
**	The "Blowfish" algorithm is in the public domain. It uses
**	a Feistal network (similar to IDEA). It has no known
**	weaknesses, but is still relatively new. Blowfish is particularly strong
**	against brute force attacks. It is also quite strong against linear and
**	differential cryptanalysis. Its weakness is that it takes a relatively
**	long time to set up with a new key (1/100th of a second on a P6-200).
**	The time to set up a key is equivalent to encrypting 4240 bytes.
*/
class BlowfishEngine {
	public:
		BlowfishEngine(void) : IsKeyed(false) {}
		~BlowfishEngine(void);

		void Submit_Key(void const * key, int length);

		int Encrypt(void const * plaintext, int length, void * cyphertext);
		int Decrypt(void const * cyphertext, int length, void * plaintext);

		/*
		**	This is the maximum key length supported.
		*/
		enum {MAX_KEY_LENGTH=56};

	private:
		bool IsKeyed;

		void Sub_Key_Encrypt(uint32_t & left, uint32_t & right);

		void Process_Block(void const * plaintext, void * cyphertext, uint32_t const * ptable);
		void Initialize_Tables(void);

		enum {
			ROUNDS = 16,		// Feistal round count (16 is standard).
			BYTES_PER_BLOCK=8	// The number of bytes in each cypher block (don't change).
		};

		/*
		**	Initialization data for sub keys. The initial values are constant and
		**	filled with a number generated from pi. Thus they are not random but
		**	they don't hold a weak pattern either.
		*/
		static uint32_t const P_Init[(int)ROUNDS+2];
		static uint32_t const S_Init[4][UCHAR_MAX+1];

		/*
		**	Permutation tables for encryption and decryption.
		*/
 		uint32_t P_Encrypt[(int)ROUNDS+2];
 		uint32_t P_Decrypt[(int)ROUNDS+2];

		/*
		**	S-Box tables (four).
		*/
		uint32_t bf_S[4][UCHAR_MAX+1];
};

#endif
