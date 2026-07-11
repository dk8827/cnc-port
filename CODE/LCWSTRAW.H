/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef LCWSTRAW_H
#define LCWSTRAW_H


#include	"straw.h"

/*
**	This class handles LCW compression/decompression to the data stream that is drawn through
**	this class. Note that for compression, two internal buffers are required. For decompression
**	only one buffer is required. This changes the memory footprint of this class depending on
**	the process desired.
*/
class LCWStraw : public Straw
{
	public:
		typedef enum CompControl {
			COMPRESS,
			DECOMPRESS
		} CompControl;

		LCWStraw(CompControl control, int blocksize=1024*8);
		virtual ~LCWStraw(void);

		virtual int Get(void * source, int slen);

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
		**	LCW compression requires a safety margin when decompressing over itself. This
		**	margin is only for the worst case situation (very rare).
		*/
		int SafetyMargin;

		/*
		**	Each block has a header of this format.
		*/
		struct {
			unsigned short CompCount;		// Size of data block (compressed).
			unsigned short UncompCount;	// Bytes of uncompressed data it represents.
		} BlockHeader;

		LCWStraw(LCWStraw & rvalue);
		LCWStraw & operator = (LCWStraw const & pipe);
};


#endif
