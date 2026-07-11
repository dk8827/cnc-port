/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQMCAPTOKEN_H
#define VQMCAPTOKEN_H

/* CaptionText: This structure describes a line of text to be displayed
 *              with the video/audio.
 *
 * Size     - Size of caption in bytes.
 * OnFrame  - Frame number to display caption.
 * OffFrame - Frame number to clear caption.
 * Flags    - Display modifiers.
 * CPF      - Characters to draw per frame.
 * Xpos     - X pixel position to display caption.
 * Ypos     - Y pixel position to display caption.
 * BgPen    - Background pen to use.
 * FgPen    - Foreground pen to use.
 * Text     - Text string to display. (WORD aligned)
 */
typedef struct _CaptionText {
	unsigned short Size;
	unsigned short OnFrame;
	unsigned short OffFrame;
	unsigned char  Flags;
	char           CPF;
	unsigned short Xpos;
	unsigned short Ypos;
	char           BgPen;
	char           FgPen;
	char           Text[];
} CaptionText;

/* CaptionText flag definitions. */
#define CTF_JUSTIFY	(3<<0)  /* Justification field. */
#define CTF_ABS     (0<<0)  /* Use absolute X,Y positions. */
#define CTF_CENTER  (1<<0)  /* Justify on Center */
#define CTF_LEFT    (2<<0)  /* Justify on left */
#define CTF_RIGHT   (3<<0)  /* Justify on right */
#define CTF_FLASH   (1<<4)  /* Flash text. */

/* Function prototypes. */
long BuildCaptions(char *name, char *buffer);

#endif /* VQMCAPTOKEN_H */

