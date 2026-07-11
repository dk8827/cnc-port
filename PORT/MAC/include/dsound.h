#pragma once

#include <windows.h>

#ifndef DS_OK
#define DS_OK 0
#endif

#ifndef DSERR_BUFFERLOST
#define DSERR_BUFFERLOST 0x88780096L
#endif

#define DSSCL_PRIORITY 2
#define DSSCL_EXCLUSIVE 3
#define DSBCAPS_PRIMARYBUFFER 0x00000001L
#define DSBCAPS_CTRLVOLUME 0x00000080L
#define DSBPLAY_LOOPING 0x00000001L
#define DSBSTATUS_PLAYING 0x00000001L
#define DSBSTATUS_LOOPING 0x00000004L

struct tWAVEFORMATEX {
	WORD wFormatTag;
	WORD nChannels;
	DWORD nSamplesPerSec;
	DWORD nAvgBytesPerSec;
	WORD nBlockAlign;
	WORD wBitsPerSample;
	WORD cbSize;
};

struct tDSBUFFERDESC {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwBufferBytes;
	DWORD dwReserved;
	LPWAVEFORMATEX lpwfxFormat;
};

class IDirectSoundBuffer {
	public:
		HRESULT Lock(DWORD, DWORD, void **audio1, DWORD *bytes1, void **audio2, DWORD *bytes2, DWORD)
		{
			if (audio1) *audio1 = 0;
			if (bytes1) *bytes1 = 0;
			if (audio2) *audio2 = 0;
			if (bytes2) *bytes2 = 0;
			return DSERR_BUFFERLOST;
		}
		HRESULT Unlock(void *, DWORD, void *, DWORD) { return DS_OK; }
		HRESULT Play(DWORD, DWORD, DWORD) { return DS_OK; }
		HRESULT Stop(void) { return DS_OK; }
		HRESULT Restore(void) { return DS_OK; }
		HRESULT GetStatus(DWORD *status) { if (status) *status = 0; return DS_OK; }
		HRESULT SetFormat(LPWAVEFORMATEX) { return DS_OK; }
		HRESULT SetVolume(LONG) { return DS_OK; }
		HRESULT SetCurrentPosition(DWORD) { return DS_OK; }
		HRESULT GetCurrentPosition(DWORD *play, DWORD *write) { if (play) *play = 0; if (write) *write = 0; return DS_OK; }
		ULONG Release(void) { delete this; return 0; }
};

class IDirectSound {
	public:
		HRESULT SetCooperativeLevel(HWND, DWORD) { return DS_OK; }
		HRESULT CreateSoundBuffer(LPDSBUFFERDESC, LPDIRECTSOUNDBUFFER *buffer, void *)
		{
			if (buffer) *buffer = new IDirectSoundBuffer;
			return DS_OK;
		}
		ULONG Release(void) { delete this; return 0; }
};

static inline HRESULT DirectSoundCreate(void *, LPDIRECTSOUND *sound, void *)
{
	if (sound) *sound = new IDirectSound;
	return DS_OK;
}
