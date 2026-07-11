/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef INI_H
#define INI_H

#include	<stdlib.h>
#include	"listnode.h"
#include	"pipe.h"
#include	"wwfile.h"
#include	"pk.h"
#include	"fixed.h"
#include	"crc.h"
#include	"search.h"

/*
**	This is an INI database handler class. It handles a database with a disk format identical
**	to the INI files commonly used by Windows.
*/
class INIClass {
	public:
		INIClass(void) {}
		~INIClass(void);

		/*
		**	Fetch and store INI data.
		*/
		bool Load(FileClass & file);
		bool Load(FileClass const & file) {return(Load(const_cast<FileClass &>(file)));};
		bool Load(Straw & file);
		int Save(FileClass & file) const;
		int Save(Pipe & file) const;

		/*
		**	Erase all data within this INI file manager.
		*/
		bool Clear(char const * section = 0, char const * entry = 0);

		int Line_Count(char const * section) const;
		bool Is_Loaded(void) const {return(!SectionList.Is_Empty());}
		int Size(void) const;
		bool Is_Present(char const * section, char const * entry = 0) const {if (entry == 0) return(Find_Section(section) != 0);return(Find_Entry(section, entry) != 0);}

		/*
		**	Fetch the number of sections in the INI file or verify if a specific
		**	section is present.
		*/
		int Section_Count(void) const;
		bool Section_Present(char const * section) const {return(Find_Section(section) != NULL);}

		/*
		**	Fetch the number of entries in a section or get a particular entry in a section.
		*/
		int Entry_Count(char const * section) const;
		char const * Get_Entry(char const * section, int index) const;

		/*
		**	Get the various data types from the section and entry specified.
		*/
		int Get_String(char const * section, char const * entry, char const * defvalue, char * buffer, int size) const;
		int Get_Int(char const * section, char const * entry, int defvalue=0) const;
		int Get_Hex(char const * section, char const * entry, int defvalue=0) const;
		bool Get_Bool(char const * section, char const * entry, bool defvalue=false) const;
		int Get_TextBlock(char const * section, char * buffer, int len) const;
		int Get_UUBlock(char const * section, void * buffer, int len) const;
		PKey Get_PKey(bool fast) const;
		fixed Get_Fixed(char const * section, char const * entry, fixed defvalue) const;

		/*
		**	Put a data type to the section and entry specified.
		*/
		bool Put_Fixed(char const * section, char const * entry, fixed value);
		bool Put_String(char const * section, char const * entry, char const * string);
		bool Put_Hex(char const * section, char const * entry, int number);
		bool Put_Int(char const * section, char const * entry, int number, int format=0);
		bool Put_Bool(char const * section, char const * entry, bool value);
		bool Put_TextBlock(char const * section, char const * text);
		bool Put_UUBlock(char const * section, void const * block, int len);
		bool Put_PKey(PKey const & key);

	protected:
		enum {MAX_LINE_LENGTH=128};

		/*
		**	The value entries for the INI file are stored as objects of this type.
		**	The entry identifier and value string are combined into this object.
		*/
		struct INIEntry : Node<INIEntry> {
			INIEntry(char * entry = 0, char * value = 0) : Entry(entry), Value(value) {}
			~INIEntry(void) {free(Entry);Entry = 0;free(Value);Value = 0;}
			int Index_ID(void) const {return(CRCEngine()(Entry, strlen(Entry)));};

			char * Entry;
			char * Value;
		};

		/*
		**	Each section (bracketed) is represented by an object of this type. All entries
		**	subordinate to this section are attached.
		*/
		struct INISection : Node<INISection> {
			INISection(char * section) : Section(section) {}
			~INISection(void) {free(Section);Section = 0;EntryList.Delete();}
			INIEntry * Find_Entry(char const * entry) const;
			int Index_ID(void) const {return(CRCEngine()(Section, strlen(Section)));};

			char * Section;
			List<INIEntry> EntryList;
			IndexClass<INIEntry *>EntryIndex;
		};

		/*
		**	Utility routines to help find the appropriate section and entry objects.
		*/
		INISection * Find_Section(char const * section) const;
		INIEntry * Find_Entry(char const * section, char const * entry) const;
		static void Strip_Comments(char * buffer);

		/*
		**	This is the list of all sections within this INI file.
		*/
		List<INISection> SectionList;

		IndexClass<INISection *> SectionIndex;
};


#endif
