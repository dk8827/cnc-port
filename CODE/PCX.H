/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef RA95_PCX_ALIAS_H
#define RA95_PCX_ALIAS_H

#include "filepcx.h"

class PaletteClass;

int Write_PCX_File(FileClass & file, GraphicBufferClass & pic, PaletteClass * palette);

#endif
