/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef VQACAPTION_H
#define VQACAPTION_H


#define VQACAPTIONS_ON		0

/*---------------------------------------------------------------------------
 * STRUCTURES AND RELATED DEFINITIONS
 *-------------------------------------------------------------------------*/

/* CaptionNode: Node describing a caption to process.
 *
 * Succ    - Pointer to the next node in the list (successor).
 * Pred    - Pointer to the previous node in the list (predecessor).
 * Flags   - Status flags.
 * CapText - Pointer to the CaptionText being processed.
 * Char    - Pointer to current character in the string.
 * CurX    - Current X position.
 * CurY    - Current Y position.
 * BoundW  - Bounding width of text.
 * BoundH  - Bounding height of text.
 */
typedef struct _CaptionNode {
	struct _CaptionNode *Succ;
	struct _CaptionNode *Pred;
	unsigned short      Flags;
	CaptionText         *Captext;
	char                *Char;
	unsigned short      CurX;
	unsigned short      CurY;
	unsigned short      BoundW;
	unsigned short      BoundH;
} CaptionNode;

/* CaptionNode flag definitions. */
#define CNB_USED 0  /* This node is being used. */
#define CNF_USED (1<<CNB_USED)


/* CaptionList: Double linked list of outstanding captions to process.
 *
 * Head     - Pointer to the first node in the list.
 * Tail     - Always NULL
 * TailPred - Pointer to the last node in the list.
 */
typedef struct _CaptionList {
	CaptionNode *Head;
	CaptionNode *Tail;
	CaptionNode *TailPred;
} CaptionList;


/* CaptionInfo:
 *
 * Next   - Pointer to the next caption to be processed.
 * List   - List of pending captions to process.
 * Font   - Font to use for this caption.
 * BoundX - X position of bounding box.
 * BoundY - Y position of bounding box.
 * BoundW - Width of bounding box.
 * BoundH - Height of bounding box.
 * Buffer - Caption chunk buffer.
 */
typedef struct _CaptionInfo {
	CaptionText    *Next;
	CaptionList    List;
	void           *Font;
	char           FontHeight;
	char           FontWidth;
	void           *Buffer;
} CaptionInfo;


/*---------------------------------------------------------------------------
 * FUNCTION PROTOTYPES
 *-------------------------------------------------------------------------*/

CaptionInfo *OpenCaptions(void *captions, void *font);
void CloseCaptions(CaptionInfo *cap);
void DoCaptions(CaptionInfo *cap, unsigned long frame);

#endif /* VQACAPTION_H */

