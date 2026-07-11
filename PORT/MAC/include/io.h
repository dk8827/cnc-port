#pragma once

#include "dos.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define _access access
#define _close close
#define _lseek lseek
#define _open open
#define _read read
#define _unlink unlink
#define _write write

#ifdef __cplusplus
extern "C" {
#endif

long filelength(int handle);
long tell(int handle);
int eof(int handle);
int sopen(char const *path, int oflag, int shflag, ...);

#ifdef __cplusplus
}
#endif
