/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef LZOPIPE_H
#define LZOPIPE_H

#include	"pipe.h"


/*
**	Performs LZO compression/decompression on the data stream that is piped through this
**	class. The data is compressed in blocks so of small enough size to be compressed
**	quickly and large enough size to get decent compression rates.
*/
class LZOPipe : public Pipe
{
	public:
		typedef enum CompControl {
			COMPRESS,
			DECOMPRESS
		} CompControl;

		LZOPipe(CompControl, int blocksize=1024*8);
		virtual ~LZOPipe(void);

		virtual int Flush(void);
		virtual int Put(void const * source, int slen);

	private:
		/*
		**	This tells the pipe if it should be decompressing or compressing the data stream.
		*/
		CompControl Control;

		/*
		**	The number of bytes accumulated into the staging buffer.
		*/
		int Counter;

		/*
		**	Pointer to the working buffer that compression/decompression will use.
		*/
		char * Buffer;
		char * Buffer2;

		/*
		**	The working block size. Data will be compressed in chunks of this size.
		*/
		int BlockSize;

		/*
		**	Probably dont need this anymore as LZO decompresses into a staging buffer.
		*/
		int SafetyMargin;

		/*
		**	Each block has a header of this format.
		*/
		struct {
			unsigned short CompCount;		// Size of data block (compressed).
			unsigned short UncompCount;	// Bytes of uncompressed data it represents.
		} BlockHeader;

		LZOPipe(LZOPipe & rvalue);
		LZOPipe & operator = (LZOPipe const & pipe);
};


#endif
