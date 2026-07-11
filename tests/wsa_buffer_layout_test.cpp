#include "wsa_file_format.h"

#include <assert.h>

int main()
{
	/* GREYERTH.WSA's header value; shrinking it makes in-place LCW overlap. */
	assert(WSA_Delta_Buffer_Size(0x383bU) == 0x383bU);
	assert(WSA_Minimum_Buffer_Size(64U, 0U, 0x383bU) == 64U + 0x383bU);
	assert(WSA_Minimum_Buffer_Size(64U, 320U * 200U, 0x383bU) == 64U + 320U * 200U + 0x383bU);
	return 0;
}
