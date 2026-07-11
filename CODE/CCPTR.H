/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef CCPTR_H
#define CCPTR_H

/*
**	The CCPtr class is designed for a specific purpose. It functions like a pointer except that
**	it requires no fixups for saving and loading. If pointer fixups are not an issue, than using
**	regular pointers would be more efficient.
*/
template<class T>
class CCPtr
{
	public:
		CCPtr(void) : ID(-1) {};
		CCPtr(NoInitClass const & ) {};
		CCPtr(T * ptr);

		operator T * (void) const {
			if (ID == -1) return(NULL);
			assert(Heap != NULL && (unsigned)ID < Heap->Length());
			return((T*) (*Heap)[ID]);
		}
		T & operator * (void) const {
			assert(Heap != NULL && (unsigned)ID < Heap->Length());
			return(*(T*)(*Heap)[ID]);
		}
		T * operator -> (void) const {
			if (ID == -1) return(NULL);
			assert(Heap != NULL && (unsigned)ID < Heap->Length());
			return((T*) (*Heap)[ID]);
		}

		bool Is_Valid(void) const {return(ID != -1);}

		bool operator == (CCPtr<T> const & rvalue) const {return(ID == rvalue.ID);}
		bool operator != (CCPtr<T> const & rvalue) const {return(ID != rvalue.ID);}
		bool operator > (CCPtr<T> const & rvalue) const;
		bool operator <= (CCPtr<T> const & rvalue) const {return (rvalue > *this);}
		bool operator < (CCPtr<T> const & rvalue) const {return (*this != rvalue && rvalue > *this);}
		bool operator >= (CCPtr<T> const & rvalue) const {return (*this == rvalue || rvalue > *this);}

		long Raw(void) const {return(ID);}
		void Set_Raw(long value) {ID = value;}

	private:

		static FixedIHeapClass * Heap;

		/*
		**	This is the ID number of the object it refers to. By using an ID number, this class can
		**	be saved and loaded without pointer fixups.
		*/
		int ID;
};

/*
**	These template helper functions tell the compiler what to do in the
**	ambiguous case of a CCPtr on one side and a regular type pointer on the
**	other side. In such a case the compiler could create a temp CCPtr object
**	OR call the conversion operator on the existing CCPtr object. Either way
**	is technically valid, but the compiler doesn't know which is better so it
**	generates an error. These routines force the conversion operator rather than
**	creating a temporary object. This presumes that the conversion operator is
**	cheaper than constructing a temporary and that cheaper solutions are desirable.
*/
template<class T>
int operator == (CCPtr<T> & lvalue, T * rvalue)
{
	return((T*)lvalue == rvalue);
}

template<class T>
int operator == (T * lvalue, CCPtr<T> & rvalue)
{
	return(lvalue == (T*)rvalue);
}

#endif
