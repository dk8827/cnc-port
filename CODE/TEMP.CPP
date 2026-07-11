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

	int 	hfile;
	long	length;

	hfile = _lopen(lpstrFileName, OF_READ | OF_SHARE_DENY_WRITE);
	if (hfile == -1) {
		return(0);
	}

	hfile = _lopen(lpstrFileName, OF_READ | OF_SHARE_EXCLUSIVE);
	if (hfile == -1) {
		hfile = _lcreat(lpstrFileName, 0);
		if (hfile == -1)	{
			return(0);
		}
	}
	length = sizeof(MobileClass);
	if (length != _lwrite(hfile, this, lenght)) {
		_lclose(hfile);
		return(0);
	}
	_lclose(hfile);
	return(TRUE);
}