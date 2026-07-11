/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#include	"function.h"
#include	"drop.h"


DropListClass::DropListClass(int id, char * text, int max_len, TextPrintType flags, int x, int y, int w, int h, void const * up, void const * down) :
	EditClass(id, text, max_len, flags, x, y, w, 9*RESFACTOR, ALPHANUMERIC),
	IsDropped(false),
	ListHeight(h),
	DropButton(0, down, x+w, y),
	List(0, x, y+Get_Build_Frame_Height(down), w+Get_Build_Frame_Width(down), h, flags, up, down)
{
	Fancy_Text_Print("", 0, 0, 0, 0, flags);
	EditClass::Height = FontHeight+1;
	List.Make_Peer(*this);
	DropButton.Make_Peer(*this);
}


void DropListClass::Zap(void)
{
	Collapse();
	List.Zap();
	DropButton.Zap();
	EditClass::Zap();
}

DropListClass & DropListClass::Add(LinkClass & object)
{
	DropButton.Add(object);
	return((DropListClass &)EditClass::Add(object));
}

DropListClass & DropListClass::Add_Tail(LinkClass & object)
{
	DropButton.Add_Tail(object);
	return((DropListClass &)EditClass::Add_Tail(object));
}

DropListClass & DropListClass::Add_Head(LinkClass & object)
{
	DropButton.Add_Head(object);
	return((DropListClass &)EditClass::Add_Head(object));
}

DropListClass * DropListClass::Remove(void)
{
	if (IsDropped) {
		Collapse();
	}
	DropButton.Remove();
	return((DropListClass *)EditClass::Remove());
}

int DropListClass::Add_Item(char const * text)
{
	strncpy(String, text, MaxLength);
	Flag_To_Redraw();
	return(List.Add_Item(text));
}

char const * DropListClass::Current_Item(void)
{
	return(List.Current_Item());
}

int DropListClass::Current_Index(void)
{
	return(List.Current_Index());
}

void DropListClass::Set_Selected_Index(int index)
{
	if ((unsigned)index < List.Count()) {
		List.Set_Selected_Index(index);
		strcpy(String, List.Get_Item(Current_Index()));
	} else {
		String[0] = '\0';
	}
}


void DropListClass::Clear_Focus(void)
{
	Collapse();
}

void DropListClass::Peer_To_Peer(unsigned flags, KeyNumType & key, ControlClass & whom)
{
	if (&whom == &DropButton) {
		if (flags & LEFTRELEASE) {
			if (IsDropped) {
				Collapse();
				key = (KeyNumType)(ID | KN_BUTTON);
			} else {
				Expand();
			}
		}
	}

	if (&whom == &List) {
		strncpy(String, List.Current_Item(), MaxLength);
		Flag_To_Redraw();
		key = (KeyNumType)(ID | KN_BUTTON);
	}
}

void DropListClass::Expand(void)
{
	if (!IsDropped) {
		List.X = X;
		List.Y = Y+9*RESFACTOR;
		List.Width = Width;
		List.Height = ListHeight;
		List.Add(Head_Of_List());
		List.Flag_To_Redraw();
		IsDropped = true;
	}
}

void DropListClass::Collapse(void)
{
	if (IsDropped) {
		List.Remove();
		IsDropped = false;
	}
}


DropListClass & DropListClass::operator = (DropListClass const & list)
{
	if (this == &list) return(*this);
	EditClass::operator =(list);
	List = list.List;
	IsDropped = list.IsDropped;
	ListHeight = list.ListHeight;
	DropButton = list.DropButton;
	List.Make_Peer(*this);
	DropButton.Make_Peer(*this);
	return(*this);
}


DropListClass::DropListClass(DropListClass const & list) :
	EditClass(list),
	IsDropped(list.IsDropped),
	ListHeight(list.ListHeight),
	DropButton(list.DropButton),
	List(list.List)
{
	List.Make_Peer(*this);
	DropButton.Make_Peer(*this);
}


void DropListClass::Set_Position(int x, int y)
{
	EditClass::Set_Position(x, y);
	List.Set_Position(x, y + Get_Build_Frame_Height(DropButton.Get_Shape_Data()));
	DropButton.Set_Position(x + Width, y);
}


void DropListClass::Set_Selected_Index(char const * text)
{
	if (text) {
		for (int index = 0; index < Count(); index++) {
			if (stricmp(text, List.Get_Item(index)) == 0) {
				Set_Selected_Index(index);
				break;
			}
		}
	}
}

#ifdef WOLAPI_INTEGRATION
void DropListClass::Flag_To_Redraw(void)
{
	if( IsDropped )
		List.Flag_To_Redraw();
	EditClass::Flag_To_Redraw();
}
#endif
