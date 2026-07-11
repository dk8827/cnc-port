/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef _LZW_H
#define _LZW_H

#include	"buff.h"

class LZWEngine
{
	public:
		LZWEngine(void);

		int Compress(Buffer const & input, Buffer const & output);
		int Uncompress(Buffer const & input, Buffer const & output);

		void Reset(void);

	private:
		typedef short CodeType;
		struct CodeClass {
			CodeType CodeValue;
			CodeType ParentCode;
			char CharValue;

			CodeClass(void) {}
			CodeClass(CodeType code, CodeType parent, char c) : CodeValue(code), ParentCode(parent), CharValue(c) {}

			enum {UNUSED=-1};
			void Make_Unused(void) {CodeValue = UNUSED;}
			bool Is_Unused(void) const {return(CodeValue == UNUSED);}
			bool Is_Matching(CodeType code, char c) const {return(ParentCode == code && CharValue == c);}
		};

		enum {
			BITS=12,
			MAX_CODE=((1 << BITS ) - 1),
			FIRST_CODE=257,
			END_OF_STREAM=256,
			TABLE_SIZE=5021
		};
		CodeClass dict[TABLE_SIZE];

		char decode_stack[TABLE_SIZE];

		int Find_Child_Node(CodeType parent_code, char child_character);
		int Decode_String(char * ptr, CodeType code);
		static int Make_LZW_Hash(CodeType code, char character);
};


int LZW_Compress(Buffer const & inbuff, Buffer const & outbuff);
int LZW_Uncompress(Buffer const & inbuff, Buffer const & outbuff);

#endif
