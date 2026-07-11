/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef _LZO_H
#define _LZO_H

#include "lzoconf.h"

int lzo1x_1_compress ( 	const lzo_byte *in ,
								lzo_uint  in_len,
                         lzo_byte *out,
								lzo_uint *out_len,
                         lzo_voidp wrkmem );


int lzo1x_decompress	(  const lzo_byte *in ,
								lzo_uint  in_len,
								lzo_byte *out,
								lzo_uint *out_len,
                         lzo_voidp );





#endif
