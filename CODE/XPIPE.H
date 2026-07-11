/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef XPIPE_H
#define XPIPE_H

#include	"pipe.h"
#include	"wwfile.h"
#include	"buff.h"

/*
**	This is a simple store-into-buffer pipe terminator. Use it as the final link in a pipe process
**	that needs to store the data into a memory buffer. This can only serve as the final
**	link in the chain of pipe segments.
*/
class BufferPipe : public Pipe
{
	public:
		BufferPipe(Buffer const & buffer) : BufferPtr(buffer), Index(0) {}
		BufferPipe(void * buffer, int length) : BufferPtr(buffer, length), Index(0) {}
		virtual int Put(void const * source, int slen);

	private:
		Buffer BufferPtr;
		int Index;

//		void * Buffer;
//		int Length;

		bool Is_Valid(void) {return(BufferPtr.Is_Valid());}
		BufferPipe(BufferPipe & rvalue);
		BufferPipe & operator = (BufferPipe const & pipe);
};


/*
**	This is a store-to-file pipe terminator. Use it as the final link in a pipe process that
**	needs to store the data to a file. This can only serve as the last link in the chain
**	of pipe segments.
*/
class FilePipe : public Pipe
{
	public:
		FilePipe(FileClass * file) : File(file), HasOpened(false) {}
		FilePipe(FileClass & file) : File(&file), HasOpened(false) {}
		virtual ~FilePipe(void);

		virtual int Put(void const * source, int slen);
		virtual int End(void);

	private:
		FileClass * File;
		bool HasOpened;

		bool Valid_File(void) {return(File != NULL);}
		FilePipe(FilePipe & rvalue);
		FilePipe & operator = (FilePipe const & pipe);

};

#endif
