/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifdef WOLAPI_INTEGRATION

//	SEditDlg.h - "SimpleEditDlgClass": An ok/cancel type dialog with a single edit box.
//	ajw 07/21/98

#include "function.h"

class SimpleEditDlgClass
{
public:
	SimpleEditDlgClass( int iDialogWidth, const char* szTitle, const char* szPrompt, int iEditCharsAccept,
							const char* szPrompt2 = NULL, int iEditCharsAccept2 = 0 );
	virtual ~SimpleEditDlgClass();

	const char* Show();					//	Shows dialog, returns text of button pressed.
										//	Unless SetButtons() is used, value will be TXT_OK or TXT_CANCEL string values.

	void		SetButtons( const char* szOk, const char* szCancel, const char* szMiddle = NULL );

	char		szEdit[ 300 ];			//	iEditCharsAccept upper limit.
	char		szEdit2[ 300 ];

protected:
	int			iDialogWidth;			//	X pixels width of entire dialog.
	char*		szTitle;				//	Title of dialog, or NULL for no title.

	char*		szPrompt;				//	Text appearing to the left of edit box.
	int			iEditCharsAccept;		//	Max length of string allowed in edit, includes null-terminator.

	char*		szPrompt2;
	int			iEditCharsAccept2;

	const char*	szOkButton;				//	Text of button that acts like an Ok button. Appears on left.
	const char*	szCancelButton;			//	Text of button that acts like an Cancel button. Appears on right.
	const char* szMiddleButton;			//	Optional middle button text. Null = no middle button.
};

#endif
