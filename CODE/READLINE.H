/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"wwfile.h"
#include	"straw.h"

void strtrim(char * buffer);
int Read_Line(FileClass & file, char * buffer, int len, bool & eof);
int Read_Line(Straw & file, char * buffer, int len, bool & eof);

