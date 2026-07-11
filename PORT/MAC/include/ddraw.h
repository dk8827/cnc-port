#pragma once

#include "windows.h"
#include "mac_sdl_runtime.h"

#include <stdlib.h>
#include <string.h>

#define DD_OK 0
#define DDERR_GENERIC ((HRESULT)0x80004005L)
#define DDERR_SURFACELOST ((HRESULT)0x887601C2L)
#define DDERR_WASSTILLDRAWING ((HRESULT)0x8876021CL)
#define DDERR_ALREADYINITIALIZED ((HRESULT)0x88760001L)
#define DDERR_BLTFASTCANTCLIP ((HRESULT)0x88760002L)
#define DDERR_CANNOTATTACHSURFACE ((HRESULT)0x88760003L)
#define DDERR_CANNOTDETACHSURFACE ((HRESULT)0x88760004L)
#define DDERR_CANTCREATEDC ((HRESULT)0x88760005L)
#define DDERR_CANTDUPLICATE ((HRESULT)0x88760006L)
#define DDERR_CANTLOCKSURFACE ((HRESULT)0x88760007L)
#define DDERR_CLIPPERISUSINGHWND ((HRESULT)0x88760008L)
#define DDERR_COLORKEYNOTSET ((HRESULT)0x88760009L)
#define DDERR_CURRENTLYNOTAVAIL ((HRESULT)0x8876000AL)
#define DDERR_DIRECTDRAWALREADYCREATED ((HRESULT)0x8876000BL)
#define DDERR_EXCEPTION ((HRESULT)0x8876000CL)
#define DDERR_EXCLUSIVEMODEALREADYSET ((HRESULT)0x8876000DL)
#define DDERR_HEIGHTALIGN ((HRESULT)0x8876000EL)
#define DDERR_HWNDALREADYSET ((HRESULT)0x8876000FL)
#define DDERR_HWNDSUBCLASSED ((HRESULT)0x88760010L)
#define DDERR_IMPLICITLYCREATED ((HRESULT)0x88760011L)
#define DDERR_INCOMPATIBLEPRIMARY ((HRESULT)0x88760012L)
#define DDERR_INVALIDCAPS ((HRESULT)0x88760013L)
#define DDERR_INVALIDCLIPLIST ((HRESULT)0x88760014L)
#define DDERR_INVALIDDIRECTDRAWGUID ((HRESULT)0x88760015L)
#define DDERR_INVALIDMODE ((HRESULT)0x88760016L)
#define DDERR_INVALIDOBJECT ((HRESULT)0x88760017L)
#define DDERR_INVALIDPARAMS ((HRESULT)0x88760018L)
#define DDERR_INVALIDPIXELFORMAT ((HRESULT)0x88760019L)
#define DDERR_INVALIDPOSITION ((HRESULT)0x8876001AL)
#define DDERR_INVALIDRECT ((HRESULT)0x8876001BL)
#define DDERR_INVALIDSURFACETYPE ((HRESULT)0x8876001CL)
#define DDERR_LOCKEDSURFACES ((HRESULT)0x8876001DL)
#define DDERR_NO3D ((HRESULT)0x8876001EL)
#define DDERR_NOALPHAHW ((HRESULT)0x8876001FL)
#define DDERR_NOANTITEARHW ((HRESULT)0x88760020L)
#define DDERR_NOBLTHW ((HRESULT)0x88760021L)
#define DDERR_NOBLTQUEUEHW ((HRESULT)0x88760022L)
#define DDERR_NOCLIPLIST ((HRESULT)0x88760023L)
#define DDERR_NOCLIPPERATTACHED ((HRESULT)0x88760024L)
#define DDERR_NOCOLORCONVHW ((HRESULT)0x88760025L)
#define DDERR_NOCOLORKEY ((HRESULT)0x88760026L)
#define DDERR_NOCOLORKEYHW ((HRESULT)0x88760027L)
#define DDERR_NOCOOPERATIVELEVELSET ((HRESULT)0x88760028L)
#define DDERR_NODC ((HRESULT)0x88760029L)
#define DDERR_NODDROPSHW ((HRESULT)0x8876002AL)
#define DDERR_NODIRECTDRAWHW ((HRESULT)0x8876002BL)
#define DDERR_NODIRECTDRAWSUPPORT ((HRESULT)0x8876002CL)
#define DDERR_NOEMULATION ((HRESULT)0x8876002DL)
#define DDERR_NOEXCLUSIVEMODE ((HRESULT)0x8876002EL)
#define DDERR_NOFLIPHW ((HRESULT)0x8876002FL)
#define DDERR_NOGDI ((HRESULT)0x88760030L)
#define DDERR_NOHWND ((HRESULT)0x88760031L)
#define DDERR_NOMIRRORHW ((HRESULT)0x88760032L)
#define DDERR_NOOVERLAYDEST ((HRESULT)0x88760033L)
#define DDERR_NOOVERLAYHW ((HRESULT)0x88760034L)
#define DDERR_NOPALETTEATTACHED ((HRESULT)0x88760035L)
#define DDERR_NOPALETTEHW ((HRESULT)0x88760036L)
#define DDERR_NORASTEROPHW ((HRESULT)0x88760037L)
#define DDERR_NOROTATIONHW ((HRESULT)0x88760038L)
#define DDERR_NOSTRETCHHW ((HRESULT)0x88760039L)
#define DDERR_NOT4BITCOLOR ((HRESULT)0x8876003AL)
#define DDERR_NOT4BITCOLORINDEX ((HRESULT)0x8876003BL)
#define DDERR_NOT8BITCOLOR ((HRESULT)0x8876003CL)
#define DDERR_NOTAOVERLAYSURFACE ((HRESULT)0x8876003DL)
#define DDERR_NOTEXTUREHW ((HRESULT)0x8876003EL)
#define DDERR_NOTFLIPPABLE ((HRESULT)0x8876003FL)
#define DDERR_NOTFOUND ((HRESULT)0x88760040L)
#define DDERR_NOTLOCKED ((HRESULT)0x88760041L)
#define DDERR_NOTPALETTIZED ((HRESULT)0x88760042L)
#define DDERR_NOVSYNCHW ((HRESULT)0x88760043L)
#define DDERR_NOZBUFFERHW ((HRESULT)0x88760044L)
#define DDERR_NOZOVERLAYHW ((HRESULT)0x88760045L)
#define DDERR_OUTOFCAPS ((HRESULT)0x88760046L)
#define DDERR_OUTOFMEMORY ((HRESULT)0x88760047L)
#define DDERR_OUTOFVIDEOMEMORY ((HRESULT)0x88760048L)
#define DDERR_OVERLAYCANTCLIP ((HRESULT)0x88760049L)
#define DDERR_OVERLAYCOLORKEYONLYONEACTIVE ((HRESULT)0x8876004AL)
#define DDERR_OVERLAYNOTVISIBLE ((HRESULT)0x8876004BL)
#define DDERR_PALETTEBUSY ((HRESULT)0x8876004CL)
#define DDERR_PRIMARYSURFACEALREADYEXISTS ((HRESULT)0x8876004DL)
#define DDERR_REGIONTOOSMALL ((HRESULT)0x8876004EL)
#define DDERR_SURFACEALREADYATTACHED ((HRESULT)0x8876004FL)
#define DDERR_SURFACEALREADYDEPENDENT ((HRESULT)0x88760050L)
#define DDERR_SURFACEBUSY ((HRESULT)0x88760051L)
#define DDERR_SURFACEISOBSCURED ((HRESULT)0x88760052L)
#define DDERR_SURFACENOTATTACHED ((HRESULT)0x88760053L)
#define DDERR_TOOBIGHEIGHT ((HRESULT)0x88760054L)
#define DDERR_TOOBIGSIZE ((HRESULT)0x88760055L)
#define DDERR_TOOBIGWIDTH ((HRESULT)0x88760056L)
#define DDERR_UNSUPPORTED ((HRESULT)0x88760057L)
#define DDERR_UNSUPPORTEDFORMAT ((HRESULT)0x88760058L)
#define DDERR_UNSUPPORTEDMASK ((HRESULT)0x88760059L)
#define DDERR_VERTICALBLANKINPROGRESS ((HRESULT)0x8876005AL)
#define DDERR_WRONGMODE ((HRESULT)0x8876005BL)
#define DDERR_XALIGN ((HRESULT)0x8876005CL)

#define DDSD_CAPS 0x00000001L
#define DDSD_HEIGHT 0x00000002L
#define DDSD_WIDTH 0x00000004L
#define DDSD_PITCH 0x00000008L
#define DDSD_LPSURFACE 0x00000800L

#define DDSCAPS_PRIMARYSURFACE 0x00000200L
#define DDSCAPS_OFFSCREENPLAIN 0x00000040L
#define DDSCAPS_SYSTEMMEMORY 0x00000800L
#define DDSCAPS_MODEX 0x00200000L

#define DDLOCK_WAIT 0x00000001L
#define DDBLT_WAIT 0x01000000L
#define DDBLT_ASYNC 0x02000000L
#define DDBLT_COLORFILL 0x00000400L
#define DDBLT_KEYSRC 0x00008000L
#define DDGBS_CANBLT 0x00000001L
#define DDGBS_ISBLTDONE 0x00000002L

#define DDCAPS_BLT 0x00000001L
#define DDCAPS_BLTQUEUE 0x00000002L
#define DDCAPS_PALETTEVSYNC 0x00000004L
#define DDCAPS_BANKSWITCHED 0x00000008L
#define DDCAPS_BLTCOLORFILL 0x00000010L
#define DDCAPS_NOHARDWARE 0x00000020L

#define E_NOTIMPL ((HRESULT)0x80004001L)

#define DDSCL_EXCLUSIVE 0x00000010L
#define DDSCL_FULLSCREEN 0x00000001L
#define DDSCL_ALLOWMODEX 0x00000040L

#define DDPCAPS_8BIT 0x00000004L
#define DDPCAPS_ALLOW256 0x00000040L

#define DDWAITVB_BLOCKBEGIN 0x00000001L

typedef struct _DDSCAPS {
	DWORD dwCaps;
} DDSCAPS, *LPDDSCAPS;

typedef struct _DDSURFACEDESC {
	DWORD dwSize;
	DWORD dwFlags;
	DWORD dwHeight;
	DWORD dwWidth;
	LONG lPitch;
	LPVOID lpSurface;
	DDSCAPS ddsCaps;
} DDSURFACEDESC, *LPDDSURFACEDESC;

typedef struct _DDCAPS {
	DWORD dwSize;
	DWORD dwVidMemTotal;
	DWORD dwVidMemFree;
	DWORD dwCaps;
	DWORD dwCaps2;
	DWORD dwCKeyCaps;
	DWORD dwFXCaps;
	DWORD dwFXAlphaCaps;
	DWORD dwPalCaps;
	DWORD dwSVCaps;
	DWORD dwAlphaBltConstBitDepths;
	DWORD dwAlphaBltPixelBitDepths;
	DWORD dwAlphaBltSurfaceBitDepths;
	DWORD dwAlphaOverlayConstBitDepths;
	DWORD dwAlphaOverlayPixelBitDepths;
	DWORD dwAlphaOverlaySurfaceBitDepths;
	DWORD dwZBufferBitDepths;
	DWORD dwVidMemTotalVisible;
	DWORD dwVidMemFreeVisible;
} DDCAPS, *LPDDCAPS;

typedef struct _DDBLTFX {
	DWORD dwSize;
	DWORD dwDDFX;
	DWORD dwROP;
	DWORD dwDDROP;
	DWORD dwRotationAngle;
	DWORD dwZBufferOpCode;
	DWORD dwZBufferLow;
	DWORD dwZBufferHigh;
	DWORD dwZBufferBaseDest;
	DWORD dwZDestConstBitDepth;
	DWORD dwZDestConst;
	DWORD dwZSrcConstBitDepth;
	DWORD dwZSrcConst;
	DWORD dwAlphaEdgeBlendBitDepth;
	DWORD dwAlphaEdgeBlend;
	DWORD dwReserved;
	DWORD dwAlphaDestConstBitDepth;
	DWORD dwAlphaDestConst;
	DWORD dwAlphaSrcConstBitDepth;
	DWORD dwAlphaSrcConst;
	DWORD dwFillColor;
} DDBLTFX, *LPDDBLTFX;

class IDirectDrawPalette {
public:
	IDirectDrawPalette(void) { memset(entries, 0, sizeof(entries)); }
	HRESULT SetEntries(DWORD, DWORD start, DWORD count, LPPALETTEENTRY palette)
	{
		if (!palette || start >= 256) return DDERR_INVALIDPARAMS;
		if (start + count > 256) count = 256 - start;
		memcpy(&entries[start], palette, sizeof(PALETTEENTRY) * count);
		MacSDL_SetPalette(entries, 256);
		return DD_OK;
	}
	ULONG Release(void) { delete this; return 0; }
	PALETTEENTRY entries[256];
};

class IDirectDrawSurface {
public:
	IDirectDrawSurface(int w, int h, DWORD caps, void *external)
		: width(w), height(h), pitch(w), caps(caps), pixels((unsigned char *)external), owns_pixels(external == 0), palette(0)
	{
		if (width < 1) width = 1;
		if (height < 1) height = 1;
		pitch = width;
		if (!pixels) {
			pixels = (unsigned char *)calloc((size_t)pitch * (size_t)height, 1);
		}
	}

	~IDirectDrawSurface(void)
	{
		if (owns_pixels) {
			free(pixels);
		}
	}

	HRESULT Lock(LPRECT, LPDDSURFACEDESC desc, DWORD, HANDLE)
	{
		if (!desc || !pixels) return DDERR_CANTLOCKSURFACE;
		desc->dwSize = sizeof(*desc);
		desc->dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_PITCH | DDSD_LPSURFACE | DDSD_CAPS;
		desc->dwWidth = width;
		desc->dwHeight = height;
		desc->lPitch = pitch;
		desc->lpSurface = pixels;
		desc->ddsCaps.dwCaps = caps;
		return DD_OK;
	}

	HRESULT Unlock(LPVOID)
	{
		if (caps & DDSCAPS_PRIMARYSURFACE) {
			MacSDL_Present8(pixels, width, height, pitch);
		}
		return DD_OK;
	}

	HRESULT Blt(LPRECT dest_rect, IDirectDrawSurface *source, LPRECT source_rect, DWORD flags, LPVOID fx)
	{
		RECT dest;
		if (dest_rect) {
			dest = *dest_rect;
		} else {
			dest.left = 0;
			dest.top = 0;
			dest.right = width;
			dest.bottom = height;
		}

		if (flags & DDBLT_COLORFILL) {
			DDBLTFX *bltfx = (DDBLTFX *)fx;
			unsigned char color = bltfx ? (unsigned char)bltfx->dwFillColor : 0;
			int left = dest.left < 0 ? 0 : dest.left;
			int top = dest.top < 0 ? 0 : dest.top;
			int right = dest.right > width ? width : dest.right;
			int bottom = dest.bottom > height ? height : dest.bottom;
			for (int y = top; y < bottom; ++y) {
				memset(pixels + y * pitch + left, color, right - left);
			}
			if (caps & DDSCAPS_PRIMARYSURFACE) {
				MacSDL_Present8(pixels, width, height, pitch);
			}
			return DD_OK;
		}

		if (!source || !source->pixels || !pixels) return DDERR_INVALIDPARAMS;

		RECT src;
		if (source_rect) {
			src = *source_rect;
		} else {
			src.left = 0;
			src.top = 0;
			src.right = source->width;
			src.bottom = source->height;
		}

		int copy_width = src.right - src.left;
		int copy_height = src.bottom - src.top;
		if (copy_width > dest.right - dest.left) copy_width = dest.right - dest.left;
		if (copy_height > dest.bottom - dest.top) copy_height = dest.bottom - dest.top;
		if (copy_width <= 0 || copy_height <= 0) return DD_OK;

		int row_start = 0;
		int row_end = copy_height;
		int row_step = 1;
		if (source == this && dest.top > src.top) {
			row_start = copy_height - 1;
			row_end = -1;
			row_step = -1;
		}

		for (int row = row_start; row != row_end; row += row_step) {
			int sy = src.top + row;
			int dy = dest.top + row;
			if (sy < 0 || sy >= source->height || dy < 0 || dy >= height) continue;

			int sx = src.left;
			int dx = dest.left;
			int width_to_copy = copy_width;
			if (sx < 0) {
				width_to_copy += sx;
				dx -= sx;
				sx = 0;
			}
			if (dx < 0) {
				width_to_copy += dx;
				sx -= dx;
				dx = 0;
			}
			if (sx + width_to_copy > source->width) width_to_copy = source->width - sx;
			if (dx + width_to_copy > width) width_to_copy = width - dx;
			if (width_to_copy > 0) {
				unsigned char *dst = pixels + dy * pitch + dx;
				unsigned char *src_pixels = source->pixels + sy * source->pitch + sx;
				if (flags & DDBLT_KEYSRC) {
					int x_start = 0;
					int x_end = width_to_copy;
					int x_step = 1;
					if (source == this && sy == dy && dx > sx) {
						x_start = width_to_copy - 1;
						x_end = -1;
						x_step = -1;
					}
					for (int x = x_start; x != x_end; x += x_step) {
						if (src_pixels[x] != 0) {
							dst[x] = src_pixels[x];
						}
					}
				} else {
					memmove(dst, src_pixels, width_to_copy);
				}
			}
		}
		if (caps & DDSCAPS_PRIMARYSURFACE) {
			MacSDL_Present8(pixels, width, height, pitch);
		}
		return DD_OK;
	}

	HRESULT GetBltStatus(DWORD flags) { return (flags & DDGBS_CANBLT) ? DDERR_NOBLTHW : DD_OK; }
	HRESULT Restore(void) { return DD_OK; }
	HRESULT Release(void) { delete this; return DD_OK; }
	HRESULT AddAttachedSurface(IDirectDrawSurface *) { return DD_OK; }
	HRESULT SetPalette(IDirectDrawPalette *new_palette) { palette = new_palette; return DD_OK; }
	HRESULT GetPalette(IDirectDrawPalette **out_palette) { if (out_palette) *out_palette = palette; return DD_OK; }
	HRESULT GetCaps(LPDDSCAPS out_caps) { if (out_caps) out_caps->dwCaps = caps; return DD_OK; }

	int width;
	int height;
	int pitch;
	DWORD caps;
	unsigned char *pixels;
	bool owns_pixels;
	IDirectDrawPalette *palette;
};

class IDirectDraw {
public:
	IDirectDraw(void) : mode_width(640), mode_height(400), mode_bpp(8) {}

	HRESULT CreateSurface(LPDDSURFACEDESC desc, IDirectDrawSurface **surface, void *)
	{
		if (!surface || !desc) return DDERR_INVALIDPARAMS;
		DWORD caps = desc->ddsCaps.dwCaps;
		int width = (caps & DDSCAPS_PRIMARYSURFACE) ? mode_width : (int)desc->dwWidth;
		int height = (caps & DDSCAPS_PRIMARYSURFACE) ? mode_height : (int)desc->dwHeight;
		void *external = (desc->dwFlags & DDSD_LPSURFACE) ? desc->lpSurface : 0;
		*surface = new IDirectDrawSurface(width, height, caps, external);
		return *surface ? DD_OK : DDERR_OUTOFMEMORY;
	}
	HRESULT SetCooperativeLevel(HWND, DWORD) { return DD_OK; }
	HRESULT SetDisplayMode(DWORD width, DWORD height, DWORD bpp)
	{
		if (!MacSDL_SetMode((int)width, (int)height)) {
			return DDERR_INVALIDMODE;
		}
		mode_width = (int)width;
		mode_height = (int)height;
		mode_bpp = (int)bpp;
		return DD_OK;
	}
	HRESULT CreatePalette(DWORD, LPPALETTEENTRY entries, IDirectDrawPalette **palette, void *)
	{
		if (!palette) return DDERR_INVALIDPARAMS;
		*palette = new IDirectDrawPalette;
		if (!*palette) return DDERR_OUTOFMEMORY;
		if (entries) {
			(*palette)->SetEntries(0, 0, 256, entries);
		}
		return DD_OK;
	}
	HRESULT QueryInterface(void const *, LPVOID *) { return DDERR_GENERIC; }
	HRESULT GetCaps(LPDDCAPS caps, LPDDCAPS hel)
	{
		if (caps) {
			memset(caps, 0, sizeof(*caps));
			caps->dwSize = sizeof(*caps);
			caps->dwCaps = DDCAPS_NOHARDWARE;
		}
		if (hel) {
			memset(hel, 0, sizeof(*hel));
			hel->dwSize = sizeof(*hel);
			hel->dwCaps = DDCAPS_NOHARDWARE;
		}
		return DD_OK;
	}
	HRESULT RestoreDisplayMode(void) { return DD_OK; }
	HRESULT Release(void) { MacSDL_Shutdown(); delete this; return DD_OK; }
	HRESULT WaitForVerticalBlank(DWORD, HANDLE) { return DD_OK; }

	int mode_width;
	int mode_height;
	int mode_bpp;
};

typedef IDirectDraw *LPDIRECTDRAW;
typedef IDirectDraw *LPDIRECTDRAW2;
typedef IDirectDrawSurface *LPDIRECTDRAWSURFACE;
typedef IDirectDrawPalette *LPDIRECTDRAWPALETTE;

static inline HRESULT DirectDrawCreate(void *, LPDIRECTDRAW *draw, void *)
{
	if (draw) {
		*draw = new IDirectDraw;
		return *draw ? DD_OK : DDERR_OUTOFMEMORY;
	}
	return DDERR_INVALIDPARAMS;
}

static const int IID_IDirectDraw2 = 0;
