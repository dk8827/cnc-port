/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMVESAVID_H
#define VQMVESAVID_H

#ifndef __WATCOMC__
#include <pharlap.h>
#else
#include "realmode.h"
#endif

/*---------------------------------------------------------------------------
 * VESA Video Modes
 *-------------------------------------------------------------------------*/

#define	VESA_640X400_256   0x100
#define	VESA_640X480_256   0x101
#define	VESA_800X600_16    0x102
#define	VESA_800X600_256   0x103
#define	VESA_1024X768_16   0x104
#define	VESA_1024X768_256  0x105
#define	VESA_1280X400_16   0x106
#define	VESA_1280X400_256  0x107
#define	VESA_TEXT_80X60    0x108
#define	VESA_TEXT_132X25   0x109
#define	VESA_TEXT_132X60   0x10C
#define	VESA_320X200_32K_1 0x10D
#define	VESA_320X200_32K_2 0x10E
#define	VESA_640X480_32K   0x110
#define	VESA_640X480_65K   0x111
#define	VESA_640X480_16M   0x112
#define	VESA_800X600_32K   0x113
#define	VESA_800X600_65K   0x114
#define	VESA_1024X768_32K  0x116
#define	VESA_1024X768_65K  0x117

#define	VESA_MIN VESA_640X400_256
#define	VESA_MAX VESA_1024X768_65K

/*---------------------------------------------------------------------------
 * Structure definitions
 *-------------------------------------------------------------------------*/

/* VESAInfo - General information about this VESA implementation.
 *            (Filled in by VESA BIOS Function 0)
 *
 * Signature    - Will always be 'VESA'
 * Version      - Version #
 * OEMString    - OEM ID string
 * Capabilities - Not defined by VESA yet
 * AvailModes   - List of available modes; terminated with -1 (0xffff)
 * TotalMemory  - ???
 * Reserved     - Pads structure to 256 bytes total
 */
typedef struct _VESAInfo {
	char           Signature[4];
	unsigned short Version;
	REALPTR        OEMString;
	unsigned long  Capabilities;
	REALPTR        AvailModes;
	unsigned short TotalMemory;
	unsigned char  Reserved[236];
} VESAInfo;

/* VESAModeInfo - Information about this VESA mode.
 *                (Filled in by VESA BIOS Function 1)
 *
 * Attributes       - bit 0: 1 = mode is supported
 *                    bit 1: 1 = optional info available
 *                    bit 2: 1 = std BIOS output functions valid in this mode
 *                    bit 3: 0 = monochrome, 1 = color
 *                    bit 4: 0 = text mode, 1 = graphics
 * WinA_Attributes  - bit 0 = window exists, bit 1=readable, bit 2= writable
 * WinB_Attributes  - bit 0 = window exists, bit 1=readable, bit 2= writable
 * WinGranularity   - smallest address boundary window can be placed upon;
 *                    size is in KB (ie 64, 32, 4)
 * WinSize          - size of windows in KB (ie 64, 32)
 * WinA_Segment     - location of Window A in CPU space (usually 0xa000)
 * WinB_Segment     - location of Window B in CPU space (usually 0xb000)
 * WinFunc          - address of window-setting function (This is provided 
 *                    as an alternative to Int 10 for speed.)
 * BytesPerScanline - # bytes per scan line
 * 
 * Optional info (available if bit 1 of Attributes is set):
 *
 * XRes             - X-resolution
 * YRes             - Y-resolution
 * XCharSize        - Horizontal size of char cell
 * YCharSize        - Vertical size of char cell
 * NumPlanes        - # of memory planes (???)
 * BitsPerPixel     - # bites per pixel
 * NumBanks         - # of banks (ie planes)
 * MemoryModel      - 00h = Text mode
 *                    01h = CGA mode
 *                    02h = Hercules
 *                    03h = 4 plane planar mode
 *                    04h = packed pixel mode (1 byte/pixel)
 *                    05h = non-chain 4, 256-color mode
 *                    06-0Fh = 
 *                    10-FFh = OEM-specific
 * BankSize         - Bank size in KB
 */
typedef struct _VESAModeInfo {
	unsigned short Attributes;
	unsigned char  WinA_Attributes;
	unsigned char  WinB_Attributes;
	unsigned short WinGranularity;
	unsigned short WinSize;
	unsigned short WinA_Segment;
	unsigned short WinB_Segment;
	REALPTR        WinFunc;
	unsigned short BytesPerScanline;
	unsigned short XRes;
	unsigned short YRes;
	unsigned char  XCharSize;
	unsigned char  YCharSize;
	unsigned char  NumPlanes;
	unsigned char  BitsPerPixel;
	unsigned char  NumBanks;
	unsigned char  MemoryModel;
	unsigned char  BankSize;
	unsigned char  NumInputPages;
	unsigned char  Reserved;
	unsigned char  RedMaskSize;
	unsigned char  RedFieldPosition;
	unsigned char  GreenMaskSize;
	unsigned char  GreenFieldPosition;
	unsigned char  BlueMaskSize; 
	unsigned char  BlueFieldPosition;
	unsigned char  RsvdMaskSize;
	unsigned char  RsvdFieldPosition;
	unsigned char  DirectColorModeInfo;
	unsigned char  pad[216];
} VESAModeInfo;

/*---------------------------------------------------------------------------
 * Function prototypes
 *-------------------------------------------------------------------------*/

long InitVESA(void);
void UninitVESA(void);
VESAModeInfo *SetVESAMode(long mode);
VESAModeInfo *ReadVESAModeInfo(long mode);
void SetVESAWindow(long grain_num);

#endif /* VQMVESAVID_H */

