/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef WINDOWS_H
#define WINDOWS_H

/*=========================================================================*/
/* The following prototypes are for the file: WINHIDE.CPP						*/
/*=========================================================================*/
void Window_Hide_Mouse(int window);
void Window_Show_Mouse(void);

/*=========================================================================*/
/* The following prototypes are for the file: WINDOWS.CPP						*/
/*=========================================================================*/
void Standard_More_Prompt(char const *prompt, int space, int fcolor, int bcolor);
void Set_More_Prompt(char const *prompt, int space, int fcolor, int bcolor);
void Set_More_On(void);
void Set_More_Off(void);
int Change_Window(int windnum);
int Change_New_Window(int windnum);
void New_Window(void);
void Window_Int_Print(int num);
void Window_Print(char const string[], ...);

/*
**	The WindowList[][8] array contains the following elements.  Use these
**	defines when accessing the WindowList.
*/
typedef enum {
	WINDOWX,			// X byte position of left edge.
	WINDOWY,			// Y pixel position of top edge.
	WINDOWWIDTH,	// Width in bytes of the window.
	WINDOWHEIGHT,	// Height in pixels of the window.
	WINDOWFCOL,		// Default foreground color.
	WINDOWBCOL,		// Default background color.
	WINDOWCURSORX,	// Current cursor X position (in rows).
	WINDOWCURSORY,	// Current cursor Y position (in lines).
	WINDOWPADDING=0x1000
} WindowIndexType;

extern int WindowList[][8];
extern int WindowColumns;
extern int WindowLines;
extern int WindowWidth;
extern unsigned int WinB;
extern unsigned int WinC;
extern unsigned int WinX;
extern unsigned int WinY;
extern unsigned int WinCx;
extern unsigned int WinCy;
extern unsigned int WinH;
extern unsigned int WinW;
extern unsigned int Window;

extern int MoreOn;
extern char *TXT_MoreText;

extern void (*Window_More_Ptr)(char const *, int, int, int);

#endif //WINDOWS_H

