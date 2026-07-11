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

   File              : sosfnct.h

   Programmer(s)     : Don Fowler, Nick Skrepetos
   Date              :

   Purpose           : Include Files For Zortech C++ Compiler

   Last Updated      :

****************************************************************************
               Copyright(c) 1993,1994 Human Machine Interfaces 
                            All Rights Reserved
****************************************************************************/

#ifndef  _SOS_FUNCTIONS
#define  _SOS_FUNCTIONS

#pragma pack(4)

WORD sosDIGILockMemory          (  VOID  );
WORD sosDIGIUnLockMemory        (  VOID  );
WORD sosDIGIInitSystem           (  LPSTR, WORD  );
WORD sosDIGIUnInitSystem         (  VOID  );
WORD sosDIGIInitDriver           (  WORD, _SOS_HARDWARE far *,
                                    _SOS_INIT_DRIVER far *, WORD far *   );
WORD sosDIGIUnInitDriver         (  WORD, BOOL, BOOL  );
WORD sosDIGILoadDriver          (  WORD, WORD, LPSTR far *, LPSTR far *, PSTR, PSTR, WORD * );
WORD sosDIGIUnLoadDriver         (  WORD  );
WORD sosDIGIGetDeviceCaps        (  WORD, LPSOSDEVICECAPS  );

#ifdef PHARLAP
LPSTR sosDIGIAllocateBuffer      (  WORD , WORD *, WORD * );
#else
LPSTR sosDIGIAllocateBuffer      (  WORD , WORD *, WORD * );
#endif

WORD sosDIGIStopSample           (  WORD, WORD  );
WORD sosDIGISamplesPlaying       (  WORD  );
BOOL sosDIGISampleDone           (  WORD, WORD  );
BOOL sosDIGISampleFilling        (  WORD, WORD  );
WORD sosDIGIStartSample          (  WORD, _SOS_START_SAMPLE far *  );
WORD sosDIGIContinueSample       (  WORD, WORD, _SOS_START_SAMPLE far * );


WORD  sosDIGIDetectInit          (  LPSTR  );
WORD  sosDIGIDetectUnInit        (  VOID  );
WORD  sosDIGIDetectFindHardware  (  WORD, _SOS_CAPABILITIES far *, WORD far * );
WORD  sosDIGIDetectFindFirst     (  _SOS_CAPABILITIES far *, WORD far *  );
WORD  sosDIGIDetectFindNext      (  _SOS_CAPABILITIES far *, WORD far *  );
WORD  sosDIGIDetectGetSettings   (  _SOS_HARDWARE far *  );
WORD  sosDIGIDetectGetCaps       (  WORD, _SOS_CAPABILITIES far *  );
WORD  sosDIGIDetectVerifySettings(  _SOS_HARDWARE far *  );
PSTR  sosGetErrorString          (  WORD  );

WORD  sosDIGILoadTimer           (  WORD , LPSTR far *, LPSTR far *, PSTR, PSTR, WORD * );
WORD  sosDIGIUnLoadTimer         (  WORD  );

WORD  sosTIMERRegisterEvent      ( WORD wCallRate, VOID ( far * lpTimerEvent )( VOID ), WORD far *lpTimerHandle );
WORD  sosTIMERInitSystem               (  WORD, WORD  );
WORD  sosTIMERUnInitSystem             (  WORD  );
WORD  sosTIMERSetRate                  (  WORD  );  
WORD  sosTIMERRemoveEvent              (  WORD );
WORD  sosTIMERAlterEventRate           (  WORD, WORD  );
WORD  sosTIMERGetEventRate             (  WORD  );
VOID far sosTIMEROldHandler            (  VOID  );
VOID far sosTIMERHandler               (  VOID  );

// functions in soscntl.c
WORD  sosDIGISetSampleVolume     ( WORD, WORD, WORD );
WORD  sosDIGIGetSampleVolume     ( WORD, WORD );
WORD  sosDIGISetChannel          ( WORD, WORD, WORD );
WORD  sosDIGIGetChannel          ( WORD, WORD );
WORD  sosDIGIGetBytesProcessed   ( WORD, WORD );
WORD  sosDIGIGetLoopCount        ( WORD, WORD );
WORD  sosDIGISetPanLocation      ( WORD, WORD, WORD );
WORD  sosDIGIGetPanLocation      ( WORD, WORD );
DWORD sosDIGISetPitch            ( WORD, WORD, DWORD );
DWORD sosDIGIGetPitch            ( WORD, WORD );
WORD  sosDIGIGetDMAPosition      ( WORD );
WORD  sosDIGISetPanSpeed         ( WORD, WORD, WORD );
WORD  sosDIGIGetPanSpeed         ( WORD, WORD );
WORD  sosDIGIGetSampleID         ( WORD, WORD );
WORD  sosDIGIGetSampleHandle     ( WORD, WORD );
WORD  sosDIGISetMasterVolume     ( WORD, WORD );
#ifdef PHARLAP
VOID  sosFreeVDSPage          ( unsigned short, unsigned short, DWORD );
WORD  sosAllocVDSPage         ( unsigned short *, unsigned short *, DWORD * );
#else
WORD  sosAllocVDSPage            ( LPSTR *, WORD *, WORD * );
VOID  sosFreeVDSPage             ( WORD, WORD, LONG );
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef PHARLAP
extern   int   cdecl sosRealFree          ( int );
extern   BOOL  cdecl  _sos_read( WORD, LPSTR, WORD, WORD * );
extern   int   cdecl sosRealAlloc( int, int *, int * );
extern   void  cdecl sosDRVFarMemCopy( LPSTR, LPSTR, WORD );
extern   int   cdecl sosGetCS( VOID );
extern   int   cdecl sosGetES( VOID );
#else
extern   int   cdecl sosRealAlloc         ( int, int *, int * );
extern   int   cdecl sosRealFree          ( int );
#endif

// sos driver functions
extern   WORD  cdecl sosDRVLockMemory     ( DWORD, DWORD );
extern   WORD  cdecl sosDRVUnLockMemory   ( DWORD, DWORD );
extern   void  cdecl sosDRVGetCapsInfo    ( LPSTR, LPSTR, _SOS_CAPABILITIES far * );
extern   void  cdecl sosDetDRVGetCapsInfo ( LPSTR, LPSTR, _SOS_CAPABILITIES far * );
extern   void  cdecl sosDRVGetCapsPtr     ( LPSTR, LPSTR, _SOS_CAPABILITIES far * );
extern   void  cdecl sosDRVInit           ( LPSTR, LPSTR, int, int, int, int, int, int );  
extern   void  cdecl sosDRVStart          ( LPSTR, LPSTR, int, int );
extern   void  cdecl sosDRVSetRate        ( LPSTR, LPSTR, int );
extern   void  cdecl sosDRVSetAction      ( LPSTR, LPSTR );
extern   void  cdecl sosDRVStop           ( LPSTR, LPSTR );
extern   void  cdecl sosDRVUnInit         ( LPSTR, LPSTR );
extern   void  cdecl sosDRVGetFillInfo    ( LPSTR, LPSTR, LPSTR, int, int, int, _SOS_FILL_INFO * );
extern   void  cdecl sosFillSampleStructs ( PSTR, LPSTR );
extern   WORD  cdecl sosDetDRVExist       ( LPSTR, LPSTR );
extern   WORD  cdecl sosDetDRVGetSettings ( LPSTR, LPSTR );
extern   WORD  cdecl sosDetDRVVerifySettings( LPSTR, WORD, WORD, WORD, LPSTR );
extern   WORD  cdecl sosDIGIInitForWindows( WORD );
extern   WORD  cdecl sosDIGIUnInitForWindows( WORD );
extern   LPSTR cdecl sosAllocateFarMem      ( WORD, PSTR, WORD * );
extern   LPSTR cdecl sosCreateAliasCS       ( LPSTR );
extern   VOID  cdecl sosFreeSelector        ( LPSTR, DWORD );
extern   LPSTR cdecl sosMAKEDOSPtr          ( PSTR );
extern   VOID  cdecl sosDetDRVSetEnvString  ( DWORD, PSTR );
extern   PSTR  cdecl sosDetDRVGetEnvString  ( DWORD );
extern   VOID  cdecl sosDetDRVEnvStringInit ( LPSTR, LPSTR );
extern   VOID  cdecl sosDRVSetupCallFunctions( LPSTR, LPSTR, LPSTR, LPSTR );
extern   WORD  cdecl sosDRVGetFreeMemory     ( VOID );
extern   WORD  cdecl sosDRVAllocVDSStruct    ( WORD, WORD *, WORD * );
extern   WORD  cdecl sosDRVFreeVDSStruct     ( WORD, WORD );
extern   WORD  cdecl sosDRVIsWindowsActive   ( VOID );
extern   WORD  cdecl sosDRVVDSGetBuffer    ( WORD );
extern   WORD  cdecl sosDRVVDSFreeBuffer   ( WORD );
extern   WORD  cdecl getDS( VOID );
extern   WORD  cdecl sosDRVMakeDMASelector   ( WORD );  
extern   WORD  cdecl sosDRVFreeDMASelector   ( WORD );  


extern   void  cdecl sosTIMERDRVInit( int wRate, void ( far * )( void ) );
extern   void  cdecl sosTIMERDRVUnInit( void );
extern   void  cdecl sosTIMERDRVHandler( void );
extern   void  cdecl sosTIMERDRVFHandler( void );
extern   void  cdecl sosTIMERDRVEnable( void );
extern   void  cdecl sosTIMERDRVDisable( void );
extern   void  cdecl sosTIMERDRVCallOld( void );
extern   void  cdecl sosTIMERDRVSetRate( WORD );    
extern   void  cdecl sosDIGITimer_Start( void );
extern   void  cdecl sosDIGITimer_End( void );
extern   void  cdecl sosDIGIDrv_Start( void );
extern   void  cdecl sosDIGIDrv_End( void );
#ifdef __cplusplus
}
#endif 

// external functions for handling system initialization and 
// uninitialization
WORD  sosEXDIGInitDriver               (  WORD, WORD, WORD, LPSTR,
                                          _SOS_HARDWARE far *, WORD *  );
WORD  sosEXDIGIUnInitDriver            (  VOID  );

WORD  sosEXDETFindDriver               (  WORD, LPSTR, _SOS_HARDWARE far *,
                                          _SOS_CAPABILITIES far *  );

// memory locking prototypes
VOID  sosDIGICaps_Start( VOID );
VOID  sosDIGICaps_End( VOID );
VOID  sosDIGIErr_Start( VOID );
VOID  sosDIGIErr_End( VOID );
VOID  sosDIGITmr_Start( VOID );
VOID  sosDIGITmr_End( VOID );
VOID  sosDIGIStart_Start( VOID );
VOID  sosDIGIStart_End( VOID );
VOID  sosDIGIPlyng_Start( VOID );
VOID  sosDIGIPlyng_End( VOID );
VOID  sosDIGIRate_Start( VOID );
VOID  sosDIGIRate_End( VOID );
VOID  sosDIGIDone_Start( VOID );
VOID  sosDIGIDone_End( VOID );
VOID  sosDIGIDetec_Start( VOID );
VOID  sosDIGIDetec_End( VOID );
VOID  sosDIGIInit_Start( VOID );
VOID  sosDIGIInit_End( VOID );
VOID  sosDIGILoad_Start( VOID );
VOID  sosDIGILoad_End( VOID );
VOID  sosDIGICntl_Start( VOID );
VOID  sosDIGICntl_End( VOID );

#pragma pack()

#endif
