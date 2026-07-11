/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include "wwstd.h"

/*=========================================================================*/
/* AUD file header type																		*/
/*=========================================================================*/
#define	AUD_FLAG_STEREO	1
#define	AUD_FLAG_16BIT		2

// PWG 3-14-95: This structure used to have bit fields defined for Stereo
//   and Bits.  These were removed because watcom packs them into a 32 bit
//   flag entry even though they could have fit in a 8 bit entry.
#pragma pack(1);
typedef struct {
	short int	Rate;				// Playback rate (hertz).
	long	Size;				// Size of data (bytes).
	unsigned char Flags;	// Holds flags for info
								//  1: Is the sample stereo?
								//  2: Is the sample 16 bits?
	unsigned char Compression;	// What kind of compression for this sample?
} AUDHeaderType;


/*=========================================================================*/
/*	There can be a different sound driver for sound effects, digitized		*/
/*	samples, and musical scores.  Each one must be of these specified			*/
/*	types.																						*/
/*=========================================================================*/
typedef enum {
	SAMPLE_NONE,		// No digitized sounds will be played.
	SAMPLE_SB,			// Sound Blaster digitized driver.
	SAMPLE_SBPRO,		// Sound Blaster Pro digitized driver.
	SAMPLE_PAS,			// Pro-Audio Spectrum digitized driver.
	SAMPLE_ADLIBG,		// Adlib-Gold digitized driver.
	SAMPLE_TANDY,		// Tandy 'compatible' driver.
	SAMPLE_PCSPKR,		// PC speaker digitized driver (The Audio Solution driver).
	SAMPLE_ADLIB,		// Adlib digitized driver (The Audio Solution driver).
	SAMPLE_TEMP=0x1000,
	SAMPLE_LAST
} Sample_Type;

typedef enum {
	SCORE_NONE,			// No scores will be played.
	SCORE_ALFX,			// Westwood's ALFX adlib compatable driver.
	SCORE_WWPCSPKR,	// Westwood's PC-speaker driver (obsolete).
	SCORE_WWTANDY,		// Westwood's PC-speaker driver with Tandy mod (obsolete).
	SCORE_PCSPKR,		// PC speaker XMIDI driver.
	SCORE_TANDY,		// Tandy XMIDI driver.
	SCORE_MT32,			// MT-32 / LAPC-1 Roland XMIDI driver.
	SCORE_CANVAS,		// Sound Canvas SC-55.
	SCORE_ADLIB,		// Adlib XMIDI driver.
	SCORE_ADLIBG,		// Adlib Gold XMIDI driver.
	SCORE_PASFM,		// Pro Audio Spectrum XMIDI driver.
	SCORE_SBFM,			// Sound Blaster XMIDI driver.
	SCORE_SBP1FM,		// Sound Blaster Pro (YM3812) XMIDI driver.
	SCORE_SBP2FM,		// Sound Blaster Pro (OPL3) XMIDI driver (Can't use with SFX_ALFX).
	SCORE_TEMP=0x1000,
	SCORE_LAST
} Score_Type;

typedef enum {
	SFX_NONE,			// No sound effects will be played.
	SFX_ALFX,			// Westwood's ALFX adlib compatable driver.
	SFX_WWPCSPKR,		// Westwood's PC-speaker driver.
	SFX_WWTANDY,		// Westwood's PC-speaker driver with Tandy mod.
	SFX_PCSPKR,			// PC speaker XMIDI driver.
	SFX_TANDY,			// Tandy XMIDI driver.
	SFX_MT32,			// MT-32 / LAPC-1 Roland XMIDI driver.
	SFX_CANVAS,			// Sound Canvas SC-55.
	SFX_ADLIB,			// Adlib XMIDI driver.
	SFX_ADLIBG,			// Adlib Gold XMIDI driver.
	SFX_PASFM,			// Pro Audio Spectrum XMIDI driver.
	SFX_SBFM,			// Sound Blaster XMIDI driver.
	SFX_SBP1FM,			// Sound Blaster Pro (YM3812) XMIDI driver.
	SFX_SBP2FM,			// Sound Blaster Pro (OPL3) XMIDI driver.
	SFX_TEMP=0x1000,
	SFX_LAST
} SFX_Type;



/*=========================================================================*/
/* The following prototypes are for the file: SOUNDIO.CPP						*/
/*=========================================================================*/
int File_Stream_Sample(char const *filename);
int File_Stream_Sample_Vol(char const *filename, int volume);
void cdecl _saveregs Sound_Callback(void);
void cdecl far __saveregs __loadds maintenance_callback(void);
void *Load_Sample(char const *filename);
long Load_Sample_Into_Buffer(char const *filename, void *buffer, long size);
long Sample_Read(int fh, void *buffer, long size);
void Free_Sample(void const *sample);
BOOL Sound_Init(int sfx, int score, int sample, int reverse_channels = FALSE);
BOOL Audio_Init(int sample, int address, int inter, int dma, int reverse_channels = FALSE);
void Sound_End(void);
void Stop_Sample(int handle);
BOOL Sample_Status(int handle);
BOOL Is_Sample_Playing(void const * sample);
void Stop_Sample_Playing(void const * sample);
int Play_Sample(void const *sample, int priority=0xFF, int volume=0xFF, signed short panloc = 0x0);
int Set_Sound_Vol(int volume);
int Set_Score_Vol(int volume);
void Fade_Sample(int handle, int ticks);

extern unsigned int DigiHandle;
extern int Misc;
extern SFX_Type SoundType;
extern Sample_Type SampleType;
