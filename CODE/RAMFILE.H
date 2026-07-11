/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RAMFILE_H
#define RAMFILE_H

#include	"wwfile.h"


class RAMFileClass : public FileClass
{
	public:
		RAMFileClass(void * buffer, int len);
		virtual ~RAMFileClass(void);

		virtual char const * File_Name(void) const {return("UNKNOWN");}
		virtual char const * Set_Name(char const * ) {return(File_Name());}
		virtual int Create(void);
		virtual int Delete(void);
		virtual int Is_Available(int forced=false);
		virtual int Is_Open(void) const;
		virtual int Open(char const * filename, int access=READ);
		virtual int Open(int access=READ);
		virtual long Read(void * buffer, long size);
		virtual long Seek(long pos, int dir=SEEK_CUR);
		virtual long Size(void);
		virtual long Write(void const * buffer, long size);
		virtual void Close(void);
		virtual unsigned long Get_Date_Time(void) {return(0);}
		virtual bool Set_Date_Time(unsigned long ) {return(true);}
		virtual void Error(int , int = false, char const * =NULL) {}

		operator char const * () {return File_Name();}

	private:

		/*
		**	Pointer to the buffer that the "file" will reside in.
		*/
		char * Buffer;

		/*
		**	The maximum size of the buffer. The file occupying the buffer
		**	may be smaller than this size.
		*/
		int MaxLength;

		/*
		**	The number of bytes in the sub-file occupying the buffer.
		*/
		int Length;

		/*
		**	The current file position offset within the buffer.
		*/
		int Offset;

		/*
		**	The file was opened with this access mode.
		*/
		int Access;

		/*
		**	Is the file currently open?
		*/
		bool IsOpen;

		/*
		**	Was the file buffer allocated during construction of this object?
		*/
		bool IsAllocated;
};




#endif
