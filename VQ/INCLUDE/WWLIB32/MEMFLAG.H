/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef MEMFLAG_H
#define MEMFLAG_H
// Memory Flags
/*
**	Memory allocation flags.  These are the flags that are passed into Alloc
**	in order to control the type of memory allocated.
*/
typedef enum {
	MEM_NORMAL = 0x0000,		// Default memory (normal).
	MEM_NEW	  = 0x0001,		// Called by the operator new and was overloaded.
	MEM_CLEAR  = 0x0002,		// Clear memory before returning.
	MEM_REAL   = 0x0004,		// Clear memory before returning.
	MEM_TEMP   = 0x0008,		// Clear memory before returning.
} MemoryFlagType;


/*=========================================================================*/
/* The following prototypes are for the file: ALLOC.CPP							*/
/*=========================================================================*/

void *Alloc(unsigned long bytes_to_alloc, MemoryFlagType flags);
void Free(void *pointer);
void *Resize_Alloc(void *original_ptr, unsigned long new_size_in_bytes);
long Ram_Free(MemoryFlagType flag);
long Heap_Size(MemoryFlagType flag);
long Total_Ram_Free(MemoryFlagType flag);


inline void * operator new(size_t size, MemoryFlagType flag) 
{
	return(Alloc(size, flag));
}
inline void * operator new[] (size_t size, MemoryFlagType flag)
{
	return(Alloc(size, flag));
}


/*=========================================================================*/
/* The following prototypes are for the file: MEM_COPY.ASM						*/
/*=========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

	extern void Mem_Copy(void *source, void *dest, unsigned long bytes_to_copy);

#ifdef __cplusplus
}
#endif


inline void *Add_Long_To_Pointer(void const *ptr, long size) 
{
 	return ((void *) ( (char const *) ptr + size));
}

extern void (*Memory_Error)(void);

extern unsigned long MinRam;		// Record of least memory at worst case.
extern unsigned long MaxRam;		// Record of total allocated at worst case.


#endif


