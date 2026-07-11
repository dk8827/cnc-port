/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/*=========================================================================*/
/* The following prototypes are for the file: SOUNDIO.CPP						*/
/*=========================================================================*/

short Decompress_Frame(void * source, void * dest, short size);
int __cdecl Stream_Sample_Vol(void *buffer, long size, BOOL (*callback);
int __cdecl Stream_Sample(void *buffer, long size, BOOL (*callback);
int __cdecl File_Stream_Sample(char const *filename);
int __cdecl File_Stream_Sample_Vol(char const *filename, int volume);
void __cdecl _saveregs _loadds Sound_Callback(void);
void __cdecl far _saveregs _loadds maintenance_callback(void);
void  __cdecl Load_Sample(char const *filename);
long __cdecl Load_Sample_Into_Buffer(char const *filename, void *buffer, long size);
long __cdecl Sample_Read(int fh, void *buffer, long size);
void __cdecl Free_Sample(void const *sample);
BOOL __cdecl Sound_Init(int sfx, int score, int sample);
void far VQA_TimerCallback(void);
BOOL Audio_Init(int sample, int address, int inter, int dma);
void __cdecl Sound_End(void);
void __cdecl Stop_Sample(int handle);
BOOL __cdecl Sample_Status(int handle);
BOOL __cdecl Is_Sample_Playing(void const * sample);
void __cdecl Stop_Sample_Playing(void const * sample);
int __cdecl Play_Sample(void const *sample);
int __cdecl Play_Sample_Vol(void const *sample, int priority, int volume);
int __cdecl Set_Sound_Vol(int volume);
int __cdecl Set_Score_Vol(int volume);
void __cdecl Fade_Sample(int handle, int ticks);