#pragma once

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifndef S_IREAD
#define S_IREAD S_IRUSR
#endif

#ifndef S_IWRITE
#define S_IWRITE S_IWUSR
#endif

#ifndef SH_DENYNO
#define SH_DENYNO 0
#endif

#ifndef SH_DENYRW
#define SH_DENYRW 0
#endif

#ifndef SH_DENYWR
#define SH_DENYWR 0
#endif

#ifndef SH_DENYRD
#define SH_DENYRD 0
#endif

#ifndef _A_NORMAL
#define _A_NORMAL 0x00
#define _A_RDONLY 0x01
#define _A_HIDDEN 0x02
#define _A_SYSTEM 0x04
#define _A_VOLID  0x08
#define _A_SUBDIR 0x10
#define _A_ARCH   0x20
#endif

#ifndef FA_RDONLY
#define FA_RDONLY _A_RDONLY
#define FA_HIDDEN _A_HIDDEN
#define FA_SYSTEM _A_SYSTEM
#define FA_LABEL  _A_VOLID
#define FA_DIREC  _A_SUBDIR
#define FA_ARCH   _A_ARCH
#endif

#ifndef _HARDERR_IGNORE
#define _HARDERR_IGNORE 0
#define _HARDERR_RETRY  1
#define _HARDERR_ABORT  2
#define _HARDERR_FAIL   3
#endif

struct find_t {
	unsigned attrib;
	unsigned wr_time;
	unsigned wr_date;
	unsigned long size;
	char name[260];
};

struct diskfree_t {
	unsigned total_clusters;
	unsigned avail_clusters;
	unsigned sectors_per_cluster;
	unsigned bytes_per_sector;
};

union REGS {
	struct {
		unsigned int ax, bx, cx, dx, si, di, cflag, flags;
	} x;
	struct {
		unsigned char al, ah, bl, bh, cl, ch, dl, dh;
	} h;
};

#ifdef __cplusplus
extern "C" {
#endif

int _dos_findfirst(char const *path, unsigned attrib, struct find_t *result);
int _dos_findnext(struct find_t *result);
int _dos_findclose(struct find_t *result);
int _dos_getdrive(unsigned *drive);
int _dos_setdrive(unsigned drive, unsigned *drives);
int _dos_getdiskfree(unsigned drive, struct diskfree_t *diskspace);
int _dos_open(char const *path, unsigned mode, int *handle);
int _dos_creat(char const *path, unsigned attrib, int *handle);
int _dos_close(int handle);
unsigned _dos_read(int handle, void *buffer, unsigned count, unsigned *bytes);
unsigned _dos_write(int handle, void const *buffer, unsigned count, unsigned *bytes);

int getdisk(void);
void setdisk(int drive);
unsigned _harderr(void (*handler)());
int int86(int interrupt_number, union REGS *inregs, union REGS *outregs);
int _int86(int interrupt_number, union REGS *inregs, union REGS *outregs);
void geninterrupt(int interrupt_number);
void delay(unsigned milliseconds);
void randomize(void);

#ifdef __cplusplus
}
#endif
