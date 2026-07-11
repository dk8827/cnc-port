/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef _MCIMOVIE_H_
#define _MCIMOVIE_H_

#include "function.h"

#ifdef MCIMPEG
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <digitalv.h>
#include "watcom.h"

class MCIMovie
	{
	public:
		MCIMovie(HWND mainWindow);
		~MCIMovie();

		bool Open(const char* name, const char* device);
		bool Play(HWND window);
		bool Pause(void);
		bool Close(void);

		LONG GetWidth(void)
			{return ((mDeviceID) ? mWidth : 0);}

		LONG GetHeight(void)
			{return ((mDeviceID) ? mHeight : 0);}

	protected:
		HWND mMainWindow; // Application window
		HWND mMCIWindow; // Callback window
		char *mName;
		UINT mDeviceID;
		MCI_OPEN_PARMS mOpenParm;
		MCI_PLAY_PARMS mPlayParm;

		// Video stream dimension
		LONG mWidth, mHeight;

	private:
		bool SizeDestination(void);
		bool AttachWindow(HWND window);

		static int mRegistered;
		static WNDCLASS mWndClass;
		static HINSTANCE mInstance;
	};

#endif // MCIMPEG
#endif // _MCIMOVIE_H_
