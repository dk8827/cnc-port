#include <ddraw.h>

#include <stdio.h>
#include <string.h>

static bool g_mode_result = true;
static PALETTEENTRY g_last_palette[256];
static int g_last_palette_count = 0;

bool MacSDL_SetMode(int, int) { return g_mode_result; }
void MacSDL_Shutdown(void) {}
void MacSDL_SetPalette(PALETTEENTRY const *entries, int count)
{
	g_last_palette_count = count;
	if (entries && count > 0) {
		if (count > 256) count = 256;
		memcpy(g_last_palette, entries, sizeof(PALETTEENTRY) * count);
	}
}
void MacSDL_Present8(unsigned char const *, int, int, int) {}
void MacSDL_PumpEvents(void) {}
bool MacSDL_QuitRequested(void) { return false; }

static int fail(char const *message)
{
	fprintf(stderr, "FAIL: %s\n", message);
	return 1;
}

static int expect_equal(unsigned char actual, unsigned char expected, char const *message)
{
	if (actual != expected) {
		fprintf(stderr, "FAIL: %s: got %u expected %u\n", message, (unsigned)actual, (unsigned)expected);
		return 1;
	}
	return 0;
}

static int expect_bytes(unsigned char const *actual, unsigned char const *expected, int count, char const *message)
{
	for (int index = 0; index < count; ++index) {
		if (actual[index] != expected[index]) {
			fprintf(stderr, "FAIL: %s at %d: got %u expected %u\n", message, index, (unsigned)actual[index], (unsigned)expected[index]);
			return 1;
		}
	}
	return 0;
}

int main(void)
{
	IDirectDrawSurface source(4, 2, 0, 0);
	IDirectDrawSurface dest(4, 2, 0, 0);
	DDSURFACEDESC src_desc;
	DDSURFACEDESC dst_desc;
	RECT rect;

	if (source.Lock(0, &src_desc, 0, 0) != DD_OK) return fail("source lock failed");
	if (dest.Lock(0, &dst_desc, 0, 0) != DD_OK) return fail("dest lock failed");

	unsigned char src_pixels[8] = { 1, 0, 2, 0, 3, 4, 0, 5 };
	memset(dst_desc.lpSurface, 9, 8);
	memcpy(src_desc.lpSurface, src_pixels, 8);

	rect.left = 0;
	rect.top = 0;
	rect.right = 4;
	rect.bottom = 2;
	if (dest.Blt(&rect, &source, &rect, DDBLT_KEYSRC | DDBLT_WAIT, 0) != DD_OK) {
		return fail("keyed blit failed");
	}

	unsigned char *dst = (unsigned char *)dst_desc.lpSurface;
	if (expect_equal(dst[0], 1, "non-zero source should copy")) return 1;
	if (expect_equal(dst[1], 9, "zero source should preserve destination")) return 1;
	if (expect_equal(dst[2], 2, "non-zero source should copy")) return 1;
	if (expect_equal(dst[3], 9, "zero source should preserve destination")) return 1;
	if (expect_equal(dst[4], 3, "non-zero source should copy")) return 1;
	if (expect_equal(dst[5], 4, "non-zero source should copy")) return 1;
	if (expect_equal(dst[6], 9, "zero source should preserve destination")) return 1;
	if (expect_equal(dst[7], 5, "non-zero source should copy")) return 1;

	IDirectDraw draw;
	DDCAPS caps;
	memset(&caps, 0xa5, sizeof(caps));
	if (draw.GetCaps(&caps, 0) != DD_OK) return fail("GetCaps failed");
	if (caps.dwSize != sizeof(caps)) return fail("GetCaps should set dwSize");
	if (caps.dwCaps != DDCAPS_NOHARDWARE) return fail("GetCaps should report no hardware acceleration");
	if (caps.dwVidMemFree != 0 || caps.dwVidMemTotal != 0) return fail("GetCaps should report no video memory");

	if (dest.GetBltStatus(DDGBS_CANBLT) != DDERR_NOBLTHW) return fail("CANBLT should report no hardware blitter");
	if (dest.GetBltStatus(DDGBS_ISBLTDONE) != DD_OK) return fail("ISBLTDONE should remain complete");

	IDirectDrawSurface scrolling(4, 5, 0, 0);
	DDSURFACEDESC scroll_desc;
	RECT scroll_src;
	RECT scroll_dst;
	if (scrolling.Lock(0, &scroll_desc, 0, 0) != DD_OK) return fail("scroll surface lock failed");
	unsigned char scroll_pixels[20] = {
		1,  2,  3,  4,
		5,  6,  7,  8,
		9, 10, 11, 12,
		13, 14, 15, 16,
		17, 18, 19, 20
	};
	memcpy(scroll_desc.lpSurface, scroll_pixels, sizeof(scroll_pixels));

	scroll_src.left = 0;
	scroll_src.top = 0;
	scroll_src.right = 4;
	scroll_src.bottom = 4;
	scroll_dst.left = 0;
	scroll_dst.top = 1;
	scroll_dst.right = 4;
	scroll_dst.bottom = 5;
	if (scrolling.Blt(&scroll_dst, &scrolling, &scroll_src, DDBLT_WAIT, 0) != DD_OK) {
		return fail("overlapping vertical self blit failed");
	}
	unsigned char scroll_expected[20] = {
		1,  2,  3,  4,
		1,  2,  3,  4,
		5,  6,  7,  8,
		9, 10, 11, 12,
		13, 14, 15, 16
	};
	if (expect_bytes((unsigned char *)scroll_desc.lpSurface, scroll_expected, 20, "overlapping vertical self blit should copy like memmove")) return 1;

	PALETTEENTRY entries[256];
	memset(entries, 0, sizeof(entries));
	entries[7].peRed = 12;
	entries[7].peGreen = 34;
	entries[7].peBlue = 56;
	IDirectDrawPalette *palette = 0;
	if (draw.CreatePalette(DDPCAPS_8BIT | DDPCAPS_ALLOW256, entries, &palette, 0) != DD_OK) {
		return fail("CreatePalette failed");
	}
	if (!palette) return fail("CreatePalette returned null palette");
	if (palette->entries[7].peRed != 12 || palette->entries[7].peGreen != 34 || palette->entries[7].peBlue != 56) {
		return fail("CreatePalette should preserve initial entries");
	}
	if (g_last_palette_count != 256 || g_last_palette[7].peGreen != 34) {
		return fail("CreatePalette should publish initial entries to SDL palette");
	}
	palette->Release();

	g_mode_result = false;
	if (draw.SetDisplayMode(320, 200, 8) != DDERR_INVALIDMODE) {
		return fail("SetDisplayMode should fail when the SDL mode cannot be created");
	}

	return 0;
}
