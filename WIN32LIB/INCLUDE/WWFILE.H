/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef WWFILE_H
#define WWFILE_H

#include	<stdio.h>

#ifndef _READ
#define	_READ	0
#endif
#ifndef _WRITE
#define	_WRITE	1
#endif

#ifndef READ
#define	READ	_READ
#endif
#ifndef WRITE
#define	WRITE	_WRITE
#endif

class FileClass
{
	public:
		virtual ~FileClass(void) {};
		virtual char const * File_Name(void) const = 0;
		virtual char const * Set_Name(char const *filename) = 0;
		virtual int Create(void) = 0;
		virtual int Delete(void) = 0;
		virtual int Is_Available(int forced=false) = 0;
		virtual int Is_Open(void) const = 0;
		virtual int Open(char const *filename, int rights=READ) = 0;
		virtual int Open(int rights=READ) = 0;
		virtual long Read(void *buffer, long size) = 0;
		virtual long Seek(long pos, int dir=SEEK_CUR) = 0;
		virtual long Size(void) = 0;
		virtual long Write(void const *buffer, long size) = 0;
		virtual void Close(void) = 0;

		operator char const * () {return File_Name();};
};

#endif
