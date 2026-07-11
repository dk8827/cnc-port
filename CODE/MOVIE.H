/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef _MPGMOVIE_H_
#define _MPGMOVIE_H_
/****************************************************************************
*
* FILE
*     MpgMovie.h
*
* DESCRIPTION
*     Movie playback using DirectShow Multimedia streaming and DirectDraw
*
* PROGRAMMER
*     Denzil E. Long, Jr.
*
* DATE
*     May 27, 1998
*
****************************************************************************/

#include <windows.h>
#include <ddraw.h>

#ifdef MPGEXPORT		  
#define DLLCALL __declspec(dllexport)
#else
#define DLLCALL __declspec(dllimport)
#endif

typedef enum
	{
	MPGCMD_ERROR = -1,
	MPGCMD_INIT = 0,
	MPGCMD_CLEANUP,
	MPGCMD_PALETTE,
	MPGCMD_UPDATE
	} MPG_CMD;

typedef enum
	{
	MPGRES_QUIT = -1,
	MPGRES_CONTINUE = 0,
	MPGRES_LOSTFOCUS,
	} MPG_RESPONSE;

typedef MPG_RESPONSE (far __stdcall *LPMPGCALLBACK)(MPG_CMD cmd, LPVOID data, LPVOID user);

extern "C"
	{
	DLLCALL void __stdcall MpgPlay(const char* name, IDirectDraw* dd,
		IDirectDrawSurface* surface, RECT* dstRect);
	DLLCALL void __stdcall MpgPause(void);
	DLLCALL void __stdcall MpgResume(void);
	DLLCALL void __stdcall MpgSetCallback(LPMPGCALLBACK callback, LPVOID user);
	}

#endif // _MPGMOVIE_H_
