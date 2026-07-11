/*
**	Command & Conquer(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* $Header:   F:\projects\c&c\vcs\code\mixfile.h_v   2.18   16 Oct 1995 16:47:22   JOE_BOSTIC  $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               *** 
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : MIXFILE.H                                                    *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : October 18, 1994                                             *
 *                                                                                             *
 *                  Last Update : October 18, 1994   [JLB]                                     *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef MIXFILE_H
#define MIXFILE_H

#include <stdint.h>
#include	<wwlib32.h>
#include	"link.h"

class MixFileClass : public LinkClass 
{
	public:
		char const *Filename;			// Filename of mixfile.

		MixFileClass(char const *filename);
		~MixFileClass(void);

		static bool Free(char const *filename);
		static void Free_All(void);
		void Free(void);
		bool Cache(void);
		static bool Cache(char const *filename);
		static bool Offset(char const *filename, void ** realptr = 0, MixFileClass ** mixfile = 0, long * offset = 0, long * size = 0);
		static void const * Retrieve(char const *filename);

		#pragma pack(push, 1)
		struct SubBlock {
			int32_t CRC;			// CRC code for embedded file.
			int32_t Offset;			// Offset from start of data section.
			int32_t Size;			// Size of data subfile.

			int operator < (SubBlock & two) const {return (CRC < two.CRC);};
			int operator > (SubBlock & two) const {return (CRC > two.CRC);};
			int operator == (SubBlock & two) const {return (CRC == two.CRC);};
		};
		#pragma pack(pop)

	private:
		static MixFileClass * Finder(char const *filename);
		long Offset(long crc, long *size = 0);

		#pragma pack(push, 1)
		typedef struct {
			int16_t	count;
			int32_t	size;
		} FileHeader;
		#pragma pack(pop)

		int Count;							// Number of sub-blocks.
		long DataSize;						// Size of raw data.
		SubBlock * Buffer;				// Array of sub blocks (could be in EMS).
		void *Data;							// Pointer to raw data.

		static MixFileClass * First;
};

#endif
