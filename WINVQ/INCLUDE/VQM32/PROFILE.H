/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMPROFILE_H
#define VQMPROFILE_H

/* Prototypes */
long GetINIInt(char const *section, char const *entry,
		long deflt, char *fname);

long GetINIString(char const *section, char const *entry, 
		char const *def, char *retbuffer, long retlen, char *fname);

long Get_Frame_Pathname(char *inifile,long anim_frame,char *ext,
		char *outbuf);

#endif /* VQMPROFILE_H */

