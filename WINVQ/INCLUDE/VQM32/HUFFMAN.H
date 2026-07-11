/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H


/* TreeNode: Huffman decoding tree node.
 *
 * count  - Weight of the node in the tree.
 * child0 - Child node 0
 * child1 - Child node 1
 */
typedef struct _TreeNode {
 	unsigned long  count;
	unsigned short child0;
	unsigned short child1;
} TreeNode;


/* HuffCode: This structure is used for storing the code for each symbol
 *            during encoding. A table of codes for each symbol is built
 *            from the Huffman tree.
 *
 * code - Code used to represent a symbol.
 * bits - Length of code in bits.
 */
typedef struct _HuffCode {
	unsigned short code;
	short          bits;
} HuffCode;


#define HUFF_EOS 256 /* End of stream symbol */

/* Prototypes */
#ifdef __cplusplus
extern "C" {
#endif

long __cdecl HuffCompress(unsigned char *data, unsigned char *buffer,
		long length, char *work);

long __cdecl HuffDecompress(unsigned char *data, unsigned char *buffer,
		long length, char *work);

void __cdecl HuffCount(unsigned char *data, TreeNode *nodes, long length,
		long zero);

void __cdecl HuffScaleCounts(TreeNode *nodes);
long __cdecl RLEHuffCounts(TreeNode *nodes, unsigned char *buffer);
long __cdecl BuildHuffTree(TreeNode *nodes);

void __cdecl ConvertToCodes(TreeNode *nodes, HuffCode *codes,
		unsigned short code, short bits, short node);

long __cdecl HuffEncode(unsigned char *data, unsigned char *buffer,
		HuffCode *codes, long length);

#ifdef __cplusplus
}
#endif

#endif /* HUFFMAN_H */

