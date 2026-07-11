/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef KEYBOARD_H
#define KEYBOARD_H

/*=========================================================================*/
/* If we have not already loaded the standard library header, than we can	*/
/*		load it.																					*/
/*=========================================================================*/

#ifndef WWSTD_H
#include "wwstd.h"
#endif


extern "C" {
	void Install_Keyboard_Interrupt(void *addr, long size);
	void	*Get_RM_Keyboard_Address(void);
	long	Get_RM_Keyboard_Size(void);
	void	Remove_Keyboard_Interrupt(void);
	int	Check_Key_Num(void);
	int	Check_Key_Bits(void);
	int	Check_Key(void);
	short	Get_Key_Num(void);
	short	Get_Key_Bits(void);
	int	Get_Key(void);
	int	KN_To_KA(int keynum);
	int	Keyboard_Attributes_On(int key_flags);
	int	Keyboard_Attributes_Off(int key_flags);
	void	Clear_KeyBuffer(void);
	int	Key_Down(int key);
	int	Key_Satisfied(int key);
	void	Stuff_Key_WORD(int code);
	void	Stuff_Key_Num(int key);
	void  Install_Mouse(int max_width, int max_height, int scr_width, int scr_height);
	void	Reset_Mouse (void) ;
	void	Remove_Mouse(void);
	int	Get_Mouse_State(void);
	int	Get_Mouse_X(void);
	int	Get_Mouse_Y(void);
	int	Get_Mouse_Disabled(void);
	void  *Set_Mouse_Cursor(int xhotspot,	int yhotspot,	void *cursor);
	void	Hide_Mouse(void);
	void	Show_Mouse(void);
	void	Conditional_Hide_Mouse(int sx_pixel, int sy_pixel, int dx_pixel, int dy_pixel);
	void	Conditional_Show_Mouse(void);


	void  __interrupt far Keyboard_Interrupt(void);
	extern int MouseQX;
	extern int MouseQY;

}


enum {
	REPEATON     = 0x0001,	/* 1:all makes into buffer, 0:only 1st make */
	TRACKEXT     = 0x0002,	/* 1:Home != keypad Home, 0:Home=keypad Home */
	FILTERONLY   = 0x0004,	/* 1:Normal BIOS operation with filter */
	CTRLALTTURBO = 0x0010,	/* 1:Allow turbo up and down in application */
	NONUMLOCK    = 0x0200,	/* 1:do NOT remap keypad to numbers */
	TASKSWITCHABLE = 0x400, /* 1:allows task switching keys thru ALT-TAB, */
									/*   ALT-ESC,CTRL-ESC */
	PASSBREAKS	 = 0x0800,	// Pass all breaks to the keyboard buffer.

	/* The following flags, if turned on, should only be used for
	   debugging purposes (remember to take out the calls when BETA */

	CTRLSON      = 0x0008,	/* 1:pass scroll lock sequence into BIOS */
	CTRLCON      = 0x0020,	/* 1:pass stop code to BIOS */
	SCROLLLOCKON = 0x0040,	/* 1:pass scroll lock key into BIOS */
	PAUSEON      = 0x0080,	/* 1:pass the pause key and seq to BIOS */
									/*   make sure FILTERONLY is set */
	BREAKON      = 0x0100,	/* 1:pass the ctrl break seq to BIOS */
	KEYMOUSE     = 0x1000,	/* 1:keypad translates into mouse moves */
	SIMLBUTTON   = 0x2000	/* 1:have space and enter keys simulate Left */
									/*   mouse button when KEYMOUSE is set */
};


/*
**	These are the codes for the various key codes that are returned from the
**	keyboard input routines Get_Key() and Input_ASCII().
*/
typedef enum {
	KA_CTRL_AT = 0,
	KA_CTRL_A,
	KA_MORE = KA_CTRL_A,
	KA_CTRL_B,
	KA_SETBKGDCOL = KA_CTRL_B,
	KA_CTRL_C,
	KA_CTRL_D,
	KA_CTRL_E,
	KA_CTRL_F,
	KA_SETFORECOL = KA_CTRL_F,
	KA_CTRL_G,
	KA_CTRL_H,
	KA_BACKSPACE = KA_CTRL_H,
	KA_CTRL_I,
	KA_TAB = KA_CTRL_I,
	KA_CTRL_J,
	KA_CTRL_K,
	KA_CTRL_L,
	KA_FORMFEED = KA_CTRL_L,
	KA_CTRL_M,
	KA_RETURN = KA_CTRL_M,
	KA_CTRL_N,

	KA_CTRL_O,
	KA_CTRL_P,
	KA_CTRL_Q,
	KA_CTRL_R,
	KA_CTRL_S,
	KA_SPCTAB = KA_CTRL_S,
	KA_CTRL_T,
	KA_CTRL_U,
	KA_CTRL_V,
	KA_CTRL_W,
	KA_CTRL_X,
	KA_SETX = KA_CTRL_X,
	KA_CTRL_Y,
	KA_SETY = KA_CTRL_Y,
	KA_CTRL_Z,
	KA_CTRL_LBRACKET,
	KA_ESC = KA_CTRL_LBRACKET,
	KA_EXTEND = KA_ESC,
	KA_CTRL_BACKSLASH,
	KA_CTRL_RBRACKET,
	KA_LITERAL = KA_CTRL_RBRACKET,
	KA_CTRL_CARROT,
	KA_CTRL_UNDERLINE,

	KA_SPACE,									/*   */
	KA_EXCLAMATION,							/* ! */
	KA_DQUOTE,									/* " */
	KA_POUND,									/* # */
	KA_DOLLAR,									/* $ */
	KA_PERCENT,									/* % */
	KA_AMPER,									/* & */
	KA_SQUOTE,									/* ' */
	KA_LPAREN,									/* ( */
	KA_RPAREN,									/* ) */
	KA_ASTERISK,								/* * */
	KA_PLUS,										/* + */
	KA_COMMA,									/* , */
	KA_MINUS,									/* - */
	KA_PERIOD,									/* . */
	KA_SLASH,									/* / */

	KA_0, KA_1, KA_2, KA_3, KA_4, KA_5, KA_6, KA_7, KA_8, KA_9,
	KA_COLON,									/* : */
	KA_SEMICOLON,								/* ; */
	KA_LESS_THAN,								/* < */
	KA_EQUAL,									/* = */
	KA_GREATER_THAN,							/* > */
	KA_QUESTION,								/* ? */

	KA_AT,										/* @ */
	KA_A,											/* A */
	KA_B,											/* B */
	KA_C,											/* C */
	KA_D,											/* D */
	KA_E,											/* E */
	KA_F,											/* F */
	KA_G,											/* G */
	KA_H,											/* H */
	KA_I,											/* I */
	KA_J,											/* J */
	KA_K,											/* K */
	KA_L,											/* L */
	KA_M,											/* M */
	KA_N,											/* N */
	KA_O,											/* O */

	KA_P,											/* P */
	KA_Q,											/* Q */
	KA_R,											/* R */
	KA_S,											/* S */
	KA_T,											/* T */
	KA_U,											/* U */
	KA_V,											/* V */
	KA_W,											/* W */
	KA_X,											/* X */
	KA_Y,											/* Y */
	KA_Z,											/* Z */
	KA_LBRACKET,								/* [ */
	KA_BACKSLASH,								/* \ */
	KA_RBRACKET,								/* ] */
	KA_CARROT,									/* ^ */
	KA_UNDERLINE,								/* _ */

	KA_GRAVE,									/* ` */
	KA_a,											/* a */
	KA_b,											/* b */
	KA_c,											/* c */
	KA_d,											/* d */
	KA_e,											/* e */
	KA_f,											/* f */
	KA_g,											/* g */
	KA_h,											/* h */
	KA_i,											/* i */
	KA_j,											/* j */
	KA_k,											/* k */
	KA_l,											/* l */
	KA_m,											/* m */
	KA_n,											/* n */
	KA_o,											/* o */

	KA_p,											/* p */
	KA_q,											/* q */
	KA_r,											/* r */
	KA_s,											/* s */
	KA_t,											/* t */
	KA_u,											/* u */
	KA_v,											/* v */
	KA_w,											/* w */
	KA_x,											/* x */
	KA_y,											/* y */
	KA_z,											/* z */
	KA_LBRACE,									/* { */
	KA_BAR,										/* | */
	KA_RBRACE,									/* ] */
	KA_TILDA,									/* ~ */
	KA_DEL,										/* not used */

	KA_ALT_F10 = 143,
	KA_ALT_F9,    KA_ALT_F8,   KA_ALT_F7,   KA_ALT_F6,   KA_ALT_F5,
	KA_ALT_F4,    KA_ALT_F3,   KA_ALT_F2,   KA_ALT_F1,

	KA_CTRL_F10,  KA_CTRL_F9,  KA_CTRL_F8,  KA_CTRL_F7,  KA_CTRL_F6,
	KA_CTRL_F5,   KA_CTRL_F4,  KA_CTRL_F3,  KA_CTRL_F2,  KA_CTRL_F1,

	KA_SHIFT_F10, KA_SHIFT_F9, KA_SHIFT_F8, KA_SHIFT_F7, KA_SHIFT_F6,
	KA_SHIFT_F5,  KA_SHIFT_F4, KA_SHIFT_F3, KA_SHIFT_F2, KA_SHIFT_F1,

	KA_DELETE,									/* <DELETE> */
	KA_INSERT,									/* <INSERT> */
	KA_PGDN,										/* <PAGE DOWN> */
	KA_DOWNRIGHT = KA_PGDN,
	KA_DOWN,										/* <DOWN ARROW> */
	KA_END,										/* <END> */
	KA_DOWNLEFT = KA_END,

	KA_RESERVED1,

	KA_RIGHT,									/* <RIGHT ARROW> */
	KA_KEYPAD5,									/* NUMERIC KEY PAD <5> */
	KA_LEFT,										/* <LEFT ARROW> */

	KA_RESERVED2,

	KA_PGUP,										/* <PAGE UP> */
	KA_UPRIGHT = KA_PGUP,
	KA_UP,										/* <UP ARROW> */
	KA_HOME,										/* <HOME> */
	KA_UPLEFT = KA_HOME,
	
	KA_RESERVED3,
	KA_RESERVED4,

	KA_F10, KA_F9, KA_F8, KA_F7, KA_F6, KA_F5, KA_F4, KA_F3, KA_F2, KA_F1,

	KA_LMOUSE,
	KA_RMOUSE,
	KA_JBUTTON1,
	KA_JBUTTON2,
	KA_J_UP,
	KA_J_RIGHT,
	KA_J_DOWN,
	KA_J_LEFT,

	KA_SHIFT_BIT = 0x0100,
	KA_CTRL_BIT  = 0x0200,
	KA_ALT_BIT   = 0x0400,
	KA_RLSE_BIT  = 0x0800,
	KA_LCOMM_BIT = 0x1000,					/* Amiga Left Comm key	*/
	KA_RCOMM_BIT = 0x2000					/* Amiga Right Comm key	*/
} KeyASCIIType;

/*
**	These are the keyboard codes that are returned from the input routines
**	Get_Key_Num and Input_Num.
*/
typedef enum {
	KN_NONE = 0,
	KN_GRAVE = 1,								/* ` */
	KN_1, KN_2, KN_3, KN_4, KN_5, KN_6, KN_7, KN_8, KN_9, KN_0,
	KN_MINUS,									/* - */
	KN_EQUAL,									/* = */

	KN_RESERVED1,

	KN_BACKSPACE,								/* <BACKSPACE> */

	KN_TAB,										/* <TAB> */
	KN_Q, KN_W, KN_E, KN_R, KN_T, KN_Y, KN_U, KN_I, KN_O, KN_P,
	KN_LBRACKET,								/* [ */
	KN_RBRACKET,								/* ] */
	KN_BACKSLASH,								/* \ */

	KN_CAPSLOCK,								/* <CAPS LOCK> */
	KN_A, KN_S, KN_D, KN_F, KN_G, KN_H, KN_J, KN_K, KN_L,
	KN_SEMICOLON,								/* ; */
	KN_SQUOTE,									/* ' */
	KN_BACKSLASH2,
	KN_RETURN,									/* <RETURN> or <ENTER> */

	KN_LSHIFT,									/* <LEFT SHIFT> */

	KN_MOUSE_MOVE,								// Indicate a mouse move (for playback of

	KN_Z, KN_X, KN_C, KN_V, KN_B, KN_N, KN_M,
	KN_COMMA,									/* , */
	KN_PERIOD,									/* . */
	KN_SLASH,									/* / */

	KN_RESERVED3,

	KN_RSHIFT,									/* <RIGHT SHIFT> */

	KN_LCTRL,									/* <LEFT CTRL> */
	KN_LCOMM,									/* for AMIGA */
	KN_LALT,										/* <LEFT ALT> */
	KN_SPACE,									/* <SPACE BAR> */
	KN_RALT,										/* <RIGHT ALT> */
	KN_RCOMM,									/* for AMIGA */
	KN_RCTRL,									/* <RIGHT CTRL> */
							/* the following are forced into key buffer */
	KN_LMOUSE,
	KN_RMOUSE,
	KN_JBUTTON1,
	KN_JBUTTON2,
	KN_J_UP,
	KN_J_RIGHT,
	KN_J_DOWN,
	KN_J_LEFT,

	KN_SPECIAL9,

	KN_SPECIAL10,

	KN_E_INSERT,								/* extended <INSERT> */
	KN_E_DELETE,								/* extended <DELETE> */

	KN_RESERVED4,
	KN_RESERVED5,

	KN_E_LEFT,									/* extended <LEFT ARROW> */
	KN_E_HOME,									/* extended <HOME> */
	KN_E_END,									/* extended <END> */

	KN_RESERVED6,

	KN_E_UP,										/* extended <UP ARROW> */
	KN_E_DOWN,									/* extended <DOWN ARROW> */
	KN_E_PGUP,									/* extended <PAGE UP> */
	KN_E_PGDN,									/* extended <PAGE DOWN> */
	KN_K_LPAREN,			/* for AMIGA */
	KN_K_RPAREN,			/* for AMIGA */
	KN_E_RIGHT,									/* extended <RIGHT ARROW> */

	KN_NUMLOCK,									/* <NUM LOCK> */
	KN_HOME,										/* num key pad 7 */
	KN_UPLEFT = KN_HOME,
	KN_LEFT,										/* num key pad 4 */
	KN_END,										/* num key pad 1 */
	KN_DOWNLEFT = KN_END,

	KN_RESERVED7,

	KN_KEYPAD_SLASH,							/* num key pad / */
	KN_UP,										/* num key pad 8 */
	KN_CENTER,									/* num key pad 5 */
	KN_DOWN,										/* num key pad 2 */
	KN_INSERT,									/* num key pad 0 */
	KN_KEYPAD_ASTERISK,						/* num key pad * */
	KN_PGUP,										/* num key pad 9 */
	KN_UPRIGHT = KN_PGUP,
	KN_RIGHT,									/* num key pad 6 */
	KN_PGDN,										/* num key pad 3 */
	KN_DOWNRIGHT = KN_PGDN,
	KN_DELETE,									/* num key pad . */
	KN_KEYPAD_MINUS,							/* num key pad - */
	KN_KEYPAD_PLUS,							/* num key pad + */

	KN_RESERVED8,

	KN_KEYPAD_RETURN,							/* num key pad <ENTER> */

	KN_RESERVED9,

	KN_ESC,
	KN_HELP,										/* for AMIGA */
	KN_F1, KN_F2, KN_F3, KN_F4, KN_F5, KN_F6, KN_F7, KN_F8, KN_F9, KN_F10,
	KN_F11,
	KN_F12,
	KN_PRNTSCRN,								/* <PRINT SCRN> */
	KN_SCROLLLOCK,								/* <SCROLL LOCK> */
	KN_PAUSE,									/* <PAUSE> */

	KN_SHIFT_BIT = 0x0100,
	KN_CTRL_BIT  = 0x0200,
	KN_ALT_BIT   = 0x0400,
	KN_RLSE_BIT  = 0x0800,
	KN_LCOMM_BIT = 0x1000,					/* Amiga Left Comm key	*/
	KN_RCOMM_BIT = 0x2000,					/* Amiga Right Comm key	*/
	KN_BUTTON    = 0x8000					/* Amiga Right Comm key	*/
} KeyNumType;

#endif
