/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef XSTRAW_H
#define XSTRAW_H

#include	"straw.h"
#include	"buff.h"
#include	"wwfile.h"
#include	<stddef.h>

/*
**	This class is used to manage a buffer as a data source. Data requests will draw from the
**	buffer supplied until the buffer is exhausted.
*/
class BufferStraw : public Straw
{
	public:
		BufferStraw(Buffer const & buffer) : BufferPtr(buffer), Index(0) {}
		BufferStraw(void const * buffer, int length) : BufferPtr((void*)buffer, length), Index(0) {}
		virtual int Get(void * source, int slen);

	private:
		Buffer BufferPtr;
		int Index;
//		void const * BufferPtr;
//		int Length;

		bool Is_Valid(void) {return(BufferPtr.Is_Valid());}
		BufferStraw(BufferStraw & rvalue);
		BufferStraw & operator = (BufferStraw const & pipe);
};

/*
**	This class is used to manage a file as a data source. Data requests will draw from the
**	file until the file has been completely read.
*/
class FileStraw : public Straw
{
	public:
		FileStraw(FileClass * file) : File(file), HasOpened(false) {}
		FileStraw(FileClass & file) : File(&file), HasOpened(false) {}
		virtual ~FileStraw(void);
		virtual int Get(void * source, int slen);

	private:
		FileClass * File;
		bool HasOpened;

		bool Valid_File(void) {return(File != NULL);}
		FileStraw(FileStraw & rvalue);
		FileStraw & operator = (FileStraw const & pipe);
};


#endif
