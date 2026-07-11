/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef IFF_H
#define IFF_H

#ifndef MISC_H
#include <misc.h>		// This is needed fro Reverse_WORD and _LONG
#endif

#ifndef MEMFLAG_H
#include <memflag.h>	// This is needed for MemoryFlagType.
#endif

#ifndef GBUFFER_H
#include <gbuffer.h>
#endif 

#define LZW_SUPPORTED			FALSE

/*=========================================================================*/
/* Iff and Load Picture system defines and enumerations							*/
/*=========================================================================*/

#define 	MAKE_ID(a,b,c,d)			((LONG) ((LONG) d << 24) | ((LONG) c << 16) | ((LONG) b <<  8) | (LONG)(a))
#define	IFFize_WORD(a)			Reverse_WORD(a)
#define	IFFize_LONG(a)			Reverse_LONG(a)


//lint -strong(AJX,PicturePlaneType)
typedef enum {
	BM_AMIGA,	// Bit plane format (8K per bitplane).
	BM_MCGA,		// Byte per pixel format (64K).

	BM_DEFAULT=BM_MCGA	// Default picture format.
} PicturePlaneType;

/*
**	This is the compression type code.  This value is used in the compressed
**	file header to indicate the method of compression used.  Note that the
**	LZW method may not be supported.
*/
//lint -strong(AJX,CompressionType)
typedef enum {
	NOCOMPRESS,		// No compression (raw data).
	LZW12,			// LZW 12 bit codes.
	LZW14,			// LZW 14 bit codes.
	HORIZONTAL,		// Run length encoding (RLE).
	LCW				// Westwood proprietary compression.
} CompressionType;

/*
**	Compressed blocks of data must start with this header structure.
**	Note that disk based compressed files have an additional two
**	leading bytes that indicate the size of the entire file.
*/
//lint -strong(AJX,CompHeaderType)
typedef struct {
	BYTE	Method;		// Compression method (CompressionType).
	BYTE	pad;			// Reserved pad byte (always 0).
	LONG	Size;			// Size of the uncompressed data.
	WORD	Skip;			// Number of bytes to skip before data.
} CompHeaderType;


/*=========================================================================*/
/* The following prototypes are for the file: IFF.CPP								*/
/*=========================================================================*/

WORD cdecl Open_Iff_File(BYTE const *filename);
VOID cdecl Close_Iff_File(WORD fh);
ULONG cdecl Get_Iff_Chunk_Size(WORD fh, LONG id);
ULONG cdecl Read_Iff_Chunk(WORD fh, LONG id, VOID *buffer, ULONG maxsize);
VOID cdecl Write_Iff_Chunk(WORD file, LONG id, VOID *buffer, LONG length);


/*=========================================================================*/
/* The following prototypes are for the file: LOADPICT.CPP						*/
/*=========================================================================*/

WORD cdecl Load_Picture(BYTE const *filename, BufferClass& scratchbuf, BufferClass& destbuf, UBYTE *palette=NULL, PicturePlaneType format=BM_DEFAULT);


/*=========================================================================*/
/* The following prototypes are for the file: LOAD.CPP							*/
/*=========================================================================*/

ULONG cdecl Load_Data(BYTE const *name, VOID *ptr, ULONG size);
ULONG cdecl Write_Data(BYTE const *name, VOID *ptr, ULONG size);
VOID * cdecl Load_Alloc_Data(BYTE const *name, MemoryFlagType flags);
ULONG cdecl Load_Uncompress(BYTE const *file, BufferClass& uncomp_buff, BufferClass& dest_buff, VOID *reserved_data=NULL);
ULONG cdecl Uncompress_Data(VOID const *src, VOID *dst);
VOID cdecl Set_Uncomp_Buffer(WORD buffer_segment, UWORD size_of_buffer);

/*=========================================================================*/
/* The following prototypes are for the file: WRITELBM.CPP						*/
/*=========================================================================*/

PUBLIC BOOL Write_LBM_File(WORD lbmhandle, BufferClass& buff, WORD bitplanes, UBYTE *palette);



/*========================= Assembly Functions ============================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=========================================================================*/
/* The following prototypes are for the file: PACK2PLN.ASM						*/
/*=========================================================================*/

extern VOID Pack_2_Plane(VOID *buffer, VOID * pageptr, WORD planebit);

/*=========================================================================*/
/* The following prototypes are for the file: LCWCOMP.ASM						*/
/*=========================================================================*/

extern ULONG LCW_Compress(VOID *source, VOID *dest, ULONG length);

/*=========================================================================*/
/* The following prototypes are for the file: LCWUNCMP.ASM						*/
/*=========================================================================*/

extern ULONG LCW_Uncompress(VOID *source, VOID *dest, ULONG length);

#ifdef __cplusplus
}
#endif
/*=========================================================================*/



#endif //IFF_H

