/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

int Dip_Text(char const *source, char *dest);
int UnDip_Text(char const *source, char *dest);
char *Extract_String(void const *data, int string);
void Fixup_Text(char const *source, char *dest);
extern char Common[];
extern char Dipthong[16][8];
