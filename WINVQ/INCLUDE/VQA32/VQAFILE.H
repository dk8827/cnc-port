/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQAFILE_H
#define VQAFILE_H

#include <vqm32/iff.h>

#ifdef __WATCOMC__
#pragma pack(1);
#endif

/*---------------------------------------------------------------------------
 * STRUCTURE DEFINITIONS AND RELATED DEFINES.
 *-------------------------------------------------------------------------*/

/* VQAHeader: VQA movie description header. (VQHD)
 *
 * Version       - VQA version.
 * Flags         - Various flags. (See below)
 * ImageWidth    - Image width in pixels.
 * ImageHeight   - Image height in pixels.
 * BlockWidth    - Block width in pixels.
 * BlockHeight   - Block height in pixels.
 * Frames        - Total number of frames in the movie.
 * FPS           - Playback rate (Frame Per Second).
 * Groupsize     - Frame grouping size (frames per codebook).
 * Num1Colors    - Number of 1 color colors.
 * CBentries     - Number of codebook entries.
 * Xpos          - X position to draw frames. (-1 = Center)
 * Ypos          - Y position to draw frames. (-1 = Center)
 * MaxFramesize  - Size of largest frame.
 * SampleRate    - Sample rate of primary audio stream.
 * Channels      - Number of channels in primary audio stream.
 * BitsPerSample - Sample bit size in primary audio stream.
 * FutureUse     - Reserved for future expansion.
 */
typedef struct _VQAHeader {
	unsigned short Version;
	unsigned short Flags;
	unsigned short Frames;
	unsigned short ImageWidth;
	unsigned short ImageHeight;
	unsigned char  BlockWidth;
	unsigned char  BlockHeight;
	unsigned char  FPS;
	unsigned char  Groupsize;
	unsigned short Num1Colors;
	unsigned short CBentries;
	unsigned short Xpos;
	unsigned short Ypos;
	unsigned short MaxFramesize;
	unsigned short SampleRate;
	unsigned char  Channels;
	unsigned char  BitsPerSample;
	unsigned short AltSampleRate;
	unsigned char  AltChannels;
	unsigned char  AltBitsPerSample;
	unsigned short FutureUse[5];
} VQAHeader;

/* Version type. */
#define VQAHD_VER1 1
#define VQAHD_VER2 2

/* VQA header flag definitions */
#define VQAHDB_AUDIO    0 /* Audio track present. */
#define VQAHDB_ALTAUDIO 1 /* Alternate audio track present. */
#define VQAHDF_AUDIO    (1<<VQAHDB_AUDIO)
#define VQAHDF_ALTAUDIO (1<<VQAHDB_ALTAUDIO)


/* Frame information (FINF) chunk definitions
 *
 * The FINF chunk contains a longword (4 bytes) entry for each
 * frame in the movie. This entry is divided into two parts,
 * flags (4 bits) and offset (28 bits).
 *
 * BITS   NAME     DESCRIPTION
 * -----------------------------------------------------------
 * 31-28  Flags    4 bitwise boolean flags.
 * 27-0   Offset   Offset in WORDS from the start of the file.
 */
#define VQAFINB_KEY  31
#define VQAFINB_PAL  30
#define VQAFINB_SYNC 29
#define VQAFINF_KEY  (1L<<VQAFINB_KEY)
#define VQAFINF_PAL  (1L<<VQAFINB_PAL)
#define VQAFINF_SYNC (1L<<VQAFINB_SYNC)

/* FINF related defines and macros. */
#define VQAFINF_OFFSET 0x0FFFFFFFL
#define VQAFINF_FLAGS  0xF0000000L
#define VQAFRAME_OFFSET(a) (((a & VQAFINF_OFFSET)<<1))

/* VQ vector pointer codes. */
#define VPC_ONE_SINGLE    0xF000 /* One single color block */
#define VPC_ONE_SEMITRANS 0xE000 /* One semitransparent block */
#define VPC_SHORT_DUMP    0xD000 /* Short dump of single color blocks */
#define VPC_LONG_DUMP     0xC000 /* Long dump of single color blocks */
#define VPC_SHORT_RUN     0xB000 /* Short run of single color blocks */
#define VPC_LONG_RUN      0xA000 /* Long run */

/* Long run codes. */
#define LRC_SEMITRANS 0xC000 /* Long run of semitransparent blocks. */
#define LRC_SINGLE    0x8000 /* Long run of single color blocks. */

/* Defines used for Run-Skip-Dump compression. */
#define MIN_SHORT_RUN_LENGTH  2
#define MAX_SHORT_RUN_LENGTH  15
#define MIN_LONG_RUN_LENGTH   2
#define MAX_LONG_RUN_LENGTH   4095
#define MIN_SHORT_DUMP_LENGTH 3
#define MAX_SHORT_DUMP_LENGTH 15
#define MIN_LONG_DUMP_LENGTH  2
#define MAX_LONG_DUMP_LENGTH  4095

#define WORD_HI_BIT 0x8000

/*---------------------------------------------------------------------------
 * VQA FILE CHUNK ID DEFINITIONS.
 *-------------------------------------------------------------------------*/

#define ID_WVQA MAKE_ID('W','V','Q','A') /* Westwood VQ Animation form. */
#define ID_VQHD MAKE_ID('V','Q','H','D') /* VQ header. */
#define ID_NAME MAKE_ID('N','A','M','E') /* Name string. */
#define ID_FINF MAKE_ID('F','I','N','F') /* Frame information. */
#define ID_VQFR MAKE_ID('V','Q','F','R') /* VQ frame container. */
#define ID_VQFK MAKE_ID('V','Q','F','K') /* VQ key frame container. */
#define ID_CBF0 MAKE_ID('C','B','F','0') /* Full codebook. */
#define ID_CBFZ MAKE_ID('C','B','F','Z') /* Full codebook (compressed). */
#define ID_CBP0 MAKE_ID('C','B','P','0') /* Partial codebook. */
#define ID_CBPZ MAKE_ID('C','B','P','Z') /* Partial codebook (compressed). */
#define ID_VPT0 MAKE_ID('V','P','T','0') /* Vector pointers. */
#define ID_VPTZ MAKE_ID('V','P','T','Z') /* Vector pointers (compressed). */
#define ID_VPTK MAKE_ID('V','P','T','K') /* Vector pointers (Delta Key). */
#define ID_VPTD MAKE_ID('V','P','T','D') /* Vector pointers (Delta). */
#define ID_VPTR MAKE_ID('V','P','T','R') /* Pointers RSD compressed. */
#define ID_VPRZ MAKE_ID('V','P','R','Z') /* Pointers RSD, lcw compressed. */
#define ID_CPL0 MAKE_ID('C','P','L','0') /* Color palette. */
#define ID_CPLZ MAKE_ID('C','P','L','Z') /* Color palette (compressed). */
#define ID_SND0 MAKE_ID('S','N','D','0') /* Sound */
#define ID_SND1 MAKE_ID('S','N','D','1') /* Sound (Zap compressed). */
#define ID_SND2 MAKE_ID('S','N','D','2') /* Sound (ADPCM compressed). */
#define ID_SNDZ MAKE_ID('S','N','D','Z') /* Sound (LCW compression). */

#define ID_SNA0 MAKE_ID('S','N','A','0') /* Sound */
#define ID_SNA1 MAKE_ID('S','N','A','1') /* Sound (Zap compressed). */
#define ID_SNA2 MAKE_ID('S','N','A','2') /* Sound (ADPCM compressed). */
#define ID_SNAZ MAKE_ID('S','N','A','Z') /* Sound (LCW compression). */

#define ID_CAP0 MAKE_ID('C','A','P','0') /* Caption text */
#define ID_EVA0 MAKE_ID('E','V','A','0') /* EVA text */

#ifdef __WATCOMC__
#pragma pack();
#endif

#endif /* VQAFILE_H */

