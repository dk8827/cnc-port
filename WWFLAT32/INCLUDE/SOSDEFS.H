/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

/****************************************************************************

   File              : sosdefs.h

   Programmer(s)     : Don Fowler, Nick Skrepetos
   Date              :

   Purpose           : Include Files For Zortech C++ Compiler

   Last Updated      :

****************************************************************************
               Copyright(c) 1993,1994 Human Machine Interfaces 
                            All Rights Reserved
****************************************************************************/


#ifndef  _SOSDEFS_DEFINED
#define  _SOSDEFS_DEFINED

#undef   _TRUE
#undef   _FALSE
#undef   _NULL
enum  
      { 
         _FALSE, 
         _TRUE 
      };

#define  _NULL  0

#ifndef  VOID
#define  VOID           void
#endif
typedef  int            BOOL;
typedef  unsigned int   UINT;
typedef  unsigned char  BYTE;
typedef  unsigned       WORD;
#ifndef  LONG
typedef  signed long    LONG;
#endif
typedef  unsigned long  DWORD;

typedef  BYTE  *        PBYTE;
typedef  char near *    PSTR;
typedef  WORD  *        PWORD;
typedef  LONG  *        PLONG;
typedef  VOID  *        PVOID;

typedef  BYTE  far   *  LPBYTE;
typedef  BYTE  far   *  LPSTR;
typedef  WORD  far   *  LPWORD;
typedef  LONG  far   *  LPLONG;
typedef  VOID  far   *  LPVOID;

typedef  BYTE  huge  *  HPBYTE;
typedef  BYTE  huge  *  HPSTR;
typedef  WORD  huge  *  HPWORD;
typedef  LONG  huge  *  HPLONG;
typedef  VOID  huge  *  HPVOID;

typedef  unsigned       HANDLE;

#endif

