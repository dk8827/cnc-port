/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/****************************************************************************
*
*  File              : soscomp.h
*  Date Created      : 6/1/94
*  Description       : 
*
*  Programmer(s)     : Nick Skrepetos
*  Last Modification : 10/1/94 - 11:37:9 AM
*  Additional Notes  : Modified by Denzil E. Long, Jr.
*
*****************************************************************************
*            Copyright (c) 1994,  HMI, Inc.  All Rights Reserved            *
****************************************************************************/

#ifndef  _SOS_COMPRESS
#define  _SOS_COMPRESS

/* compression types */
enum {
	_ADPCM_TYPE_1,
	};

/* define compression structure */
typedef struct _tagCOMPRESS_INFO {
	char       *lpSource;
	char       *lpDest;
	unsigned long dwCompSize;
	unsigned long dwUnCompSize;
	short         wBitSize;
	short			    wChannels;
	unsigned long dwSampleIndex;
	long          dwPredicted;
	long          dwDifference;
	short         wCodeBuf;
	short         wCode;
	short         wStep;
	short         wIndex;

	unsigned long dwSampleIndex2; //added BP for channel 2
	long          dwPredicted2;   //added BP for channel 2
	long          dwDifference2; 	//added BP for channel 2
	short         wCodeBuf2; 		//added BP for channel 2
	short         wCode2; 			//added BP for channel 2
	short         wStep2; 			//added BP for channel 2
	short         wIndex2; 			//added BP for channel 2
	} _SOS_COMPRESS_INFO;

/* compressed file type header */
typedef struct _tagCOMPRESS_HEADER {
	unsigned long dwType;              // type of compression
	unsigned long dwCompressedSize;    // compressed file size
	unsigned long dwUnCompressedSize;  // uncompressed file size
	unsigned long dwSourceBitSize;     // original bit size
	char          szName[16];          // file type, for error checking
	} _SOS_COMPRESS_HEADER;

/* Prototypes */

#ifdef __cplusplus
extern "C" {
#endif

void cdecl sosCODECInitStream(_SOS_COMPRESS_INFO *);
unsigned long cdecl sosCODECCompressData(_SOS_COMPRESS_INFO *,unsigned long);
unsigned long cdecl sosCODECDecompressData(_SOS_COMPRESS_INFO *,unsigned long);

#ifdef __cplusplus
}
#endif

#endif

