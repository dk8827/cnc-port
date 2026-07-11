/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BFIOFILE_H
#define BFIOFILE_H

#include	"rawfile.h"

/*
**	This derivation of the raw file class handles buffering the input/output in order to
**	achieve greater speed. The buffering is not active by default. It must be activated
**	by setting the appropriate buffer through the Cache() function.
*/
class BufferIOFileClass : public RawFileClass
{
	public:

		BufferIOFileClass(char const *filename);
		BufferIOFileClass(void);
		virtual ~BufferIOFileClass(void);

		bool Cache( long size=0, void *ptr=NULL );
		void Free( void );
		bool Commit( void );
		virtual char const * Set_Name(char const *filename);
		virtual int Is_Available(int forced=false);
		virtual int Is_Open(void) const;
		virtual int Open(char const *filename, int rights=READ);
		virtual int Open(int rights=READ);
		virtual long Read(void *buffer, long size);
		virtual long Seek(long pos, int dir=SEEK_CUR);
		virtual long Size(void);
		virtual long Write(void const *buffer, long size);
		virtual void Close(void);

		enum {MINIMUM_BUFFER_SIZE=1024};

	private:

		unsigned IsAllocated:1;
		unsigned IsOpen:1;
		unsigned IsDiskOpen:1;
		unsigned IsCached:1;
		unsigned IsChanged:1;
		unsigned UseBuffer:1;

		int BufferRights;

		void *Buffer;

		long BufferSize;
		long BufferPos;
		long BufferFilePos;
		long BufferChangeBeg;
		long BufferChangeEnd;
		long FileSize;
		long FilePos;
		long TrueFileStart;
};

#endif
