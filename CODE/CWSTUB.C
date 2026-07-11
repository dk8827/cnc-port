/*
**	Command & Conquer(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <errno.h>
#include <string.h>

char *dos4g_path()
{
	static char *paths_to_check[] = {
		"DOS4GPATH",
		"PATH"
	};
	static char fullpath[80];
	char *dos4gpath;
	int i;
	
	/* If DOS4GPATH points to an executable file name, don't bother
	   searching any paths for DOS4GW.EXE.
	*/
	if (dos4gpath = getenv("DOS4GPATH")) {
	 	strlwr(strcpy(fullpath, dos4gpath));
		if (strstr(fullpath, ".exe")) {
			return(fullpath);
		}
	}
	for( i = 0; i < sizeof(paths_to_check) / sizeof(paths_to_check[0]); i++ ) {
		_searchenv("dos4gw.exe", paths_to_check[i], fullpath);
		if (fullpath[0]) {
			return( &fullpath );
		}
	}
	return("dos4gw.exe");
}

main( int argc, char *argv[] )
{
	char	*av[4];
	auto char	cmdline[128];
	
	av[0] = dos4g_path();		/* Locate the DOS/4GW loader */
	av[1] = argv[0];			/* name of executable to run */
	av[2] = getcmd(cmdline);	/* command line */
	av[3] = NULL;				/* end of list */
#ifdef VMM
	putenv("DOS4GVM=MINMEM#2000 MAXMEM#16000 SWAPMIN#4096 SWAPINC#1024 VIRTUALSIZE#10000 SWAPFILE#CONQUER.SWP DELETESWAP @CONQUER.VMC");
#endif
#ifdef QUIET
	putenv("DOS4G=QUIET");	/* disables DOS/4GW Copyright banner */
#endif
	execvp(av[0], av);
	perror(av[0]);
	exit(1);					/* indicate error */
}
