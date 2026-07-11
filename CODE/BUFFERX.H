/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef BUFFERx_H
#define BUFFERx_H

#include	"wwfile.h"

/*
**	This is a transmuter interface designed to aid implementation of compression, encryption, or
**	data analysis classes. The Transmuter should be derived into a class that performs the necessary
**	processing.
*/
class Transmuter {
	public:
		Transmuter(void) : Output(0) {}
		virtual ~Transmuter(void) {}

		/*
		**	These are the interface function that are used to pass data to the transmuter. The
		**	default implementation of these functions do nothing other than pass the data onto
		**	the subsequent transmuter. For practical use, these functions should be overloaded to
		**	do something more useful.
		*/
		virtual void Attach(Transmuter * transmuter) {Output = transmuter;}
		virtual void Flush(void) {if (Output) Output->Flush();}
		virtual void Put(const void * input, unsigned length) {if (Output) Output->Put(input, length);}

	protected:

		/*
		**	Pointer to the output transmuter.
		*/
		Transmuter * Output;
};


class FileTransmuter {
	public:
		FileTransmuter(FileClass * file = NULL) : OutputFile(file) {}

		virtual void Attach(FileClass * file) {OutputFile = file;}
		virtual void Flush(void) {}
		virtual void Put(const void * input, unsigned length) {if (OutputFile) OutputFile->Write(input, length);}

	protected:
		FileClass * OutputFile;
};


class BufferTransmuter {
	public:
		BufferTransmuter(void * buffer = NULL) : BufferPtr(buffer) {}

		virtual void Attach(void * buffer) {BufferPtr = buffer;}
		virtual void Flush(void) {}
		virtual void Put(const void * input, unsigned length) {if (BufferPtr) {memcpy(BufferPtr, input, length);((char *&)BufferPtr) += length;}}

	protected:
		void * BufferPtr;
};


#endif


