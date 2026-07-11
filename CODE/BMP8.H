/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BMP8_H
#define BMP8_H

//#include<stdlib.h>
//#include<stdio.h>
//#include "wstypes.h"
//#include "winblows.h"

class BMP8
{
public:
	BMP8() : hBMP( NULL ), hPal( NULL ), hWnd( NULL )	{}
	~BMP8();

	bool	Init( const char* szFile, HWND hWnd );
	bool	Draw(void);  // call this from your WM_PAINT message

private:
	HBITMAP		hBMP;
	HPALETTE	hPal;
	HWND		hWnd;
};


#endif