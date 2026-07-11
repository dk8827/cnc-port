#pragma once

#include <sys/stat.h>
#include <unistd.h>

#ifndef _MAX_PATH
#define _MAX_PATH 260
#endif

#ifndef _MAX_DRIVE
#define _MAX_DRIVE 3
#endif

#ifndef _MAX_DIR
#define _MAX_DIR 256
#endif

#ifndef _MAX_FNAME
#define _MAX_FNAME 256
#endif

#ifndef _MAX_EXT
#define _MAX_EXT 256
#endif

#define _chdir chdir
#define _getcwd getcwd

static inline int _mkdir(char const *path)
{
	return mkdir(path, 0777);
}
