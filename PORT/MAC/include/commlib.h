#pragma once

typedef struct PORT {
	int status;
	int count;
} PORT;

enum {
	ASSUCCESS = 0,
	ASBUFREMPTY = -1,
	COM1 = 0,
	COM2,
	COM3,
	COM4,
	COM5,
	COM6,
	COM7,
	COM8,
	COM9
};

static inline int FastGetPortHardware(int, int *, int *) { return ASSUCCESS; }
static inline int FastSetPortHardware(int, int, int) { return ASSUCCESS; }
static inline int WriteBuffer(PORT *, char const *, unsigned long) { return ASSUCCESS; }
static inline int ReadBuffer(PORT *, char *, int) { return ASBUFREMPTY; }

