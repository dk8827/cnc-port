#include <stdio.h>
#include <string.h>

#include "wwfile.h"

bool Read_Object(void *ptr, int base_size, int class_size, FileClass &file, void *vtable);
bool Write_Object(void *ptr, int class_size, FileClass &file);
void *Get_VTable(void *ptr, int base_size);
void Set_VTable(void *ptr, int base_size, void *vtable);

class MemoryFileClass : public FileClass
{
public:
	MemoryFileClass(void) : Length(0), Offset(0) {}

	virtual char const *File_Name(void) const { return "memory"; }
	virtual char const *Set_Name(char const *) { return File_Name(); }
	virtual int Create(void) { Length = Offset = 0; return 1; }
	virtual int Delete(void) { return 1; }
	virtual int Is_Available(int = false) { return 1; }
	virtual int Is_Open(void) const { return 1; }
	virtual int Open(char const *, int = READ) { return 1; }
	virtual int Open(int = READ) { return 1; }
	virtual long Seek(long pos, int dir = SEEK_CUR)
	{
		if (dir == SEEK_SET) {
			Offset = pos;
		} else if (dir == SEEK_CUR) {
			Offset += pos;
		} else if (dir == SEEK_END) {
			Offset = Length + pos;
		}
		return Offset;
	}
	virtual long Size(void) { return Length; }
	virtual long Read(void *buffer, long size)
	{
		if (Offset + size > Length) {
			return 0;
		}
		memcpy(buffer, Buffer + Offset, size);
		Offset += size;
		return size;
	}
	virtual long Write(void const *buffer, long size)
	{
		if (Offset + size > (long)sizeof(Buffer)) {
			return 0;
		}
		memcpy(Buffer + Offset, buffer, size);
		Offset += size;
		if (Offset > Length) {
			Length = Offset;
		}
		return size;
	}
	virtual void Close(void) {}

	void Clear_Serialized_VTable(void)
	{
		memset(Buffer + sizeof(int), 0, sizeof(void *));
	}

private:
	char Buffer[128];
	long Length;
	long Offset;
};

class VTableProbeClass
{
public:
	VTableProbeClass(int value) : Value(value) {}
	virtual ~VTableProbeClass(void) {}
	virtual int Virtual_Value(void) const { return Value; }

private:
	int Value;
};

static void *Primary_VTable(VTableProbeClass *probe)
{
	void *vtable;
	memcpy(&vtable, (void *)probe, sizeof(vtable));
	return vtable;
}

int main(void)
{
	MemoryFileClass file;
	VTableProbeClass exemplar(37);
	VTableProbeClass loaded(0);
	void *vtable = Primary_VTable(&exemplar);
	void *restored_vtable;

	if (Get_VTable(&exemplar, sizeof(VTableProbeClass)) != vtable) {
		fprintf(stderr, "Get_VTable did not read the primary vtable pointer.\n");
		return 1;
	}

	if (!Write_Object(&exemplar, sizeof(VTableProbeClass), file)) {
		fprintf(stderr, "Write_Object failed.\n");
		return 2;
	}

	file.Clear_Serialized_VTable();
	file.Seek(0, SEEK_SET);
	if (!Read_Object(&loaded, sizeof(VTableProbeClass), sizeof(VTableProbeClass), file, vtable)) {
		fprintf(stderr, "Read_Object failed.\n");
		return 3;
	}

	memcpy(&restored_vtable, (void *)&loaded, sizeof(restored_vtable));
	if (restored_vtable != vtable) {
		fprintf(stderr, "Read_Object did not restore the primary vtable pointer.\n");
		return 4;
	}
	if (loaded.Virtual_Value() != 37) {
		fprintf(stderr, "Read_Object did not preserve object data.\n");
		return 5;
	}

	memset((void *)&loaded, 0, sizeof(void *));
	Set_VTable(&loaded, sizeof(VTableProbeClass), vtable);
	memcpy(&restored_vtable, (void *)&loaded, sizeof(restored_vtable));
	if (restored_vtable != vtable) {
		fprintf(stderr, "Set_VTable did not restore the primary vtable pointer.\n");
		return 6;
	}

	return 0;
}
