#pragma once

#include "windows.h"

typedef UINT MMRESULT;

#define TIME_ONESHOT 0
#define TIME_PERIODIC 1

typedef void (CALLBACK *LPTIMECALLBACK)(UINT, UINT, DWORD, DWORD, DWORD);

MMRESULT timeBeginPeriod(UINT period);
MMRESULT timeEndPeriod(UINT period);
MMRESULT timeSetEvent(UINT delay, UINT resolution, LPTIMECALLBACK callback, DWORD user, UINT flags);
MMRESULT timeKillEvent(UINT id);
DWORD timeGetTime(void);

void MacMM_PumpTimers(void);
