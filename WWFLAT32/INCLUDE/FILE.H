/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef FILE_H
#define FILE_H


#ifndef ERROR
#define	ERROR	-1
#endif

#ifndef FILETEMP_H
// This should be removed once the library is all intacked.
#include "filetemp.h"
#endif

/*=========================================================================*/
/* File IO system defines and enumerations											*/
/*=========================================================================*/

#define	XMAXPATH	80

/*
**	These are the Open_File, Read_File, and Seek_File constants.
*/
#define READ						1	// Read access.
#define WRITE						2	// Write access.
#ifndef SEEK_SET
#define SEEK_SET					0	// Seek from start of file.
#define SEEK_CUR					1	// Seek relative from current location.
#define SEEK_END					2	// Seek from end of file.
#endif


typedef enum {
	FILEB_PROCESSED=8,// Was the packed file header of this file processed?
	FILEB_PRELOAD,		// Scan for and make file resident at WWDOS_Init time?
	FILEB_RESIDENT,	// Make resident at Open_File time?
	FILEB_FLUSH,		// Un-resident at Close_File time?
	FILEB_PACKED,		// Is this file packed?
	FILEB_KEEP,			// Don't ever flush this resident file?
	FILEB_PRIORITY,	// Flush this file last?

	FILEB_LAST
} FileFlags_Type;

#define	FILEF_NONE			0
#define	FILEF_PROCESSED	(1<<FILEB_PROCESSED)
#define	FILEF_PRELOAD		(1<<FILEB_PRELOAD)
#define	FILEF_RESIDENT		(1<<FILEB_RESIDENT)
#define	FILEF_FLUSH			(1<<FILEB_FLUSH)
#define	FILEF_PACKED		(1<<FILEB_PACKED)
#define	FILEF_KEEP			(1<<FILEB_KEEP)
#define	FILEF_PRIORITY		(1<<FILEB_PRIORITY)

/*
** These errors are returned by WWDOS_Init().  All errors encountered are
** or'd together so there may be more then one error returned.  Not all
** errors are fatal, such as the cache errors.
*/
typedef enum {
	FI_SUCCESS						= 0x00,
	FI_CACHE_TOO_BIG				= 0x01,
	FI_CACHE_ALREADY_INIT		= 0x02,
	FI_FILEDATA_FILE_NOT_FOUND	= 0x04,
	FI_FILEDATA_TOO_BIG			= 0x08,
 	FI_SEARCH_PATH_NOT_FOUND	= 0x10,
 	FI_STARTUP_PATH_NOT_FOUND	= 0x20,
	FI_NO_CACHE_FOR_PRELOAD		= 0x40,
	FI_FILETABLE_NOT_INIT		= 0x80,
} FileInitErrorType;


/*
**	These are the errors that are detected by the File I/O system and
**	passed to the io error routine.
*/
//lint -strong(AJX,FileErrorType)
typedef enum {
	CANT_CREATE_FILE,
	BAD_OPEN_MODE,
	COULD_NOT_OPEN,
	TOO_MANY_FILES,
	CLOSING_NON_HANDLE,
	READING_NON_HANDLE,
	WRITING_NON_HANDLE,
	SEEKING_NON_HANDLE,
	SEEKING_BAD_OFFSET,
	WRITING_RESIDENT,
	UNKNOWN_INDEX,
	DID_NOT_CLOSE,
	FATAL_ERROR,
	FILE_NOT_LISTED,
	FILE_LENGTH_MISMATCH,
	INTERNAL_ERROR,
	MAKE_RESIDENT_ZERO_SIZE,
	RESIDENT_SORT_FAILURE,

	NUMBER_OF_ERRORS				/* MAKE SURE THIS IS THE LAST ENTRY */
} FileErrorType;

// This is here tempararaly until library is put together.
//extern WORD cdecl (*cdecl IO_Error)(FileErrorType error, BYTE const *filename);
extern short (*Open_Error)(FileErrorType, BYTE const *);

/*=========================================================================*/
/* File IO system structures																*/
/*=========================================================================*/

//lint -strong(AJX,FileDataType)
typedef struct {
	char	*Name;		// File name (include sub-directory but not volume).
	long	Size;			// File size (0=indeterminate).
	void	*Ptr;			// Resident file pointer.
	long	Start;		// Starting offset in DOS handle file.
	unsigned char	Disk;			// Disk number location.
	unsigned char	OpenCount;	// Count of open locks on resident file.
	unsigned short	Flag;			// File control flags.
} FileDataType;


/*=========================================================================*/
/* FIle IO system globals.																	*/
/*=========================================================================*/

// These are cpp errors in funtions declarations	JULIO JEREZ

// extern FileDataType cdecl FileData[];
// extern BYTE cdecl ExecPath[XMAXPATH + 1];
// extern BYTE cdecl DataPath[XMAXPATH + 1];
// extern BYTE cdecl StartPath[XMAXPATH + 1];
// extern BOOL cdecl UseCD;

// The correct syntax is  NO TYPE MODIFIER APPLY TO DATA DECLARATIONS
extern FileDataType FileData[];
extern char ExecPath[XMAXPATH + 1];
extern char DataPath[XMAXPATH + 1];
extern char StartPath[XMAXPATH + 1];
extern BOOL UseCD;



/*=========================================================================*/
/* The following prototypes are for the file: FILEINIT.CPP						*/
/*=========================================================================*/

void cdecl WWDOS_Shutdown(void);
FileInitErrorType cdecl WWDOS_Init(unsigned long cachesize, char *filedata, char *cdpath);


/*=========================================================================*/
/* The following prototypes are for the file: FILE.CPP							*/
/*=========================================================================*/

int cdecl Open_File(char const *file_name, int mode);
void cdecl Close_File(int handle);
long cdecl Read_File(int handle, void *buf, unsigned long bytes);
long cdecl Write_File(int handle, void const *buf, unsigned long bytes);
unsigned long cdecl Seek_File(int handle, long offset, int starting);
int cdecl File_Exists(char const *file_name);
unsigned long cdecl File_Size(int handle);
BOOL cdecl Is_Handle_Valid(int handle, FileErrorType error, char const *name);
int cdecl Open_File_With_Recovery( char const *file_name, unsigned int mode );


/*=========================================================================*/
/* The following prototypes are for the file: FILECACH.CPP						*/
/*=========================================================================*/

void Unfragment_File_Cache(void);
BOOL cdecl Make_File_Resident(char const *filename);
short cdecl Flush_Unused_File_Cache(short flush_keeps);
BOOL cdecl Free_Resident_File(char const *file);


/*=========================================================================*/
/* The following prototypes are for the file: FILECHNG.CPP						*/
/*=========================================================================*/

short cdecl Create_File(char const *file_name);
short cdecl Delete_File(char const *file_name);
BOOL cdecl Change_File_Size(short handle, unsigned long new_size);


/*=========================================================================*/
/* The following prototypes are for the file: FILEINFO.CPP						*/
/*=========================================================================*/

short cdecl Get_DOS_Handle(short fh);
short cdecl Free_Handles(void);
short cdecl Find_Disk_Number(char const *file_name);
short cdecl Set_File_Flags(char const *filename, short flags);
short cdecl Clear_File_Flags(char const *filename, short flags);
short cdecl Get_File_Flags(char const *filename);
BOOL cdecl Multi_Drive_Search(BOOL on);


/*=========================================================================*/
/* The following prototypes are for the file: FINDFILE.CPP						*/
/*=========================================================================*/

int cdecl Find_File(char const *file_name);
int cdecl Find_File_Index(char const *filename);



/*=========================================================================*/
/* The following prototypes are for the file: FFIRST.ASM							*/
/*=========================================================================*/

#include <dos.h>

#ifdef __cplusplus
extern "C" {
#endif

extern short Find_First(unsigned char *fname, unsigned short mode, struct find_t *ffblk);
extern short Find_Next(struct find_t *ffblk);

#ifdef __cplusplus
}
#endif




#endif // FILE_H

