#include <assert.h>
#include <string.h>

#include "windows.h"

LRESULT FAR PASCAL _export Windows_Procedure(HWND, UINT, WPARAM, LPARAM)
{
	return 0;
}

static char to_ascii(UINT vk, bool shift, bool caps)
{
	BYTE state[256];
	memset(state, 0, sizeof(state));
	if (shift) state[VK_SHIFT] = 0x80;
	if (caps) state[VK_CAPITAL] = 0x01;

	WORD out = 0;
	int result = ToAscii(vk, MapVirtualKey(vk, 0), state, &out, 0);
	assert(result == 1);
	return (char)(out & 0xFF);
}

int main()
{
	assert(to_ascii('A', false, false) == 'a');
	assert(to_ascii('A', true, false) == 'A');
	assert(to_ascii('A', false, true) == 'A');
	assert(to_ascii('A', true, true) == 'a');

	assert(to_ascii('1', false, false) == '1');
	assert(to_ascii('1', true, false) == '!');
	assert(to_ascii(VK_SPACE, false, false) == ' ');
	assert(to_ascii(VK_NONE_BD, false, false) == '-');
	assert(to_ascii(VK_NONE_BD, true, false) == '_');
	assert(to_ascii(VK_NONE_DE, false, false) == '\'');
	assert(to_ascii(VK_NONE_DE, true, false) == '"');

	return 0;
}
