/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef PLAYCD_H
#define PLAYCD_H

/* ==================================================================== */
/* Defines */
/* ==================================================================== */

#define	CHLEFT	0
#define	CHRIGHT	1
#define	CHBOTH	2

#define	AUDIO_START_MIN	1
#define	AUDIO_START_SEC  44

typedef struct {
					  unsigned short seg ;
 					  unsigned short sel ;
					} SEGSEL ;




extern "C" int  DPMI_real_alloc ( UINT , SEGSEL * , USHORT * ) ;
extern "C" int  DPMI_real_free ( SEGSEL  ) ;
extern "C" void DPMI_real_intr ( int , union REGS * , struct SREGS * );
extern "C" void DPMI_real_call ( void * funct , union REGS * , struct SREGS * );




/* ==================================================================== */
/* Data structures */
/* ==================================================================== */

// Audio Track Info request block

struct	TinfoType {
	UBYTE		Length;
	UBYTE		SubCd;
	UBYTE		Command;
	UWORD		Status;
	UBYTE		Rsvd[8];
	UBYTE		MDescr;

	UWORD		TrnsAdOff;
	UWORD		TrnsAdSeg;

	UWORD		CntTrns;
	UWORD		StSect;

	UWORD		VolIDOff;
	UWORD		VolIDSeg;

	UBYTE		TrInfo;
	UBYTE		Track;
	ULONG		Start;
	UBYTE		TrCtrl;
};

// Audio Track Status Control Block

struct	StatType {
	UBYTE		Length;
	UBYTE		SubCd;
	UBYTE		Command;
	UWORD		Status;
	UBYTE		Rsvd[8];
	UBYTE		MDescr;

	UWORD		TrnsAdOff;
	UWORD		TrnsAdSeg;

	UWORD		CntTrns;
	UWORD		StSect;

	UWORD		VolIDOff;
	UWORD		VolIDSeg;

	UBYTE		StatInfo;
	UWORD		Stat;
	ULONG		Start;
	ULONG		End;
	};

// Audio Track Volume control block

struct	VolmType	{
	UBYTE		Length;
	UBYTE		SubCd;
	UBYTE		Command;
	UWORD		Status;
	UBYTE		Rsvd[8];
	UBYTE		MDescr;

	UWORD		TrnsAdOff;
	UWORD		TrnsAdSeg;

	UWORD		CntTrns;
	UWORD		StSect;

	UWORD		VolIDOff;
	UWORD		VolIDSeg;

	UBYTE		TrInfo;
	UBYTE		In0;
	UBYTE		Vol0;   
	UBYTE		In1;
	UBYTE		Vol1;   
	UBYTE		In2;
	UBYTE		Vol2;   
	UBYTE		In3;
	UBYTE		Vol3;   
	};

// Audio Track Play request block

struct	PlayType {
	UBYTE		Length;
	UBYTE		SubCd;
	UBYTE		Command;
	UWORD		Status;
	UBYTE		Rsvd[8];
	UBYTE		AddrMd;
	ULONG		Start;
	ULONG		CntSect;
	};


// Audio Track Stop request block

struct	StopType {
	UBYTE		Length;
	UBYTE		SubCd;
	UBYTE		Command;
	UWORD		Status;
	UBYTE		Rsvd[8];
	};


/***************************************************************************
 * GetCDClass -- object which will return logical CD drive						*
 *                                                                         *
 * HISTORY:                                                                *
 *   06/04/1994 SW : Created.																*
 *=========================================================================*/
#define MAX_CD_DRIVES 26
#define NO_CD_DRIVE -1

class	GetCDClass {

protected:

	union   REGS 	regs;
	struct SREGS  sregs;

	SEGSEL 		cdDrive_addrp;
	UWORD			largestp;

	int	CDDrives[MAX_CD_DRIVES];	//Array containing CD drive letters
	int	CDCount;							//Number of available CD drives
	int	CDIndex;
	
public:

	GetCDClass(VOID);					// This is the default constructor
	~GetCDClass(VOID);				// This is the destructor

	inline	int	Get_First_CD_Drive(void);
	inline	int	Get_Next_CD_Drive(void);
	inline	int	Get_Number_Of_Drives(void) {return (CDCount);};

private:
        VOID  GetCDDrives(VOID);
	
};

/***********************************************************************************************
 * GCDC::Get_Next_CD_Drive -- return the logical drive number of the next CD drive             *
 *                                                                                             *
 *                                                                                             *
 *                                                                                             *
 * INPUT:    Nothing                                                                           *
 *                                                                                             *
 * OUTPUT:   Logical drive number of a cd drive or -1 if none                                  *
 *                                                                                             *
 * WARNINGS: None                                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *    5/21/96 3:50PM ST : Created                                                              *
 *=============================================================================================*/
inline int GetCDClass::Get_Next_CD_Drive(void)
{
	if (CDCount){
		if (CDIndex == CDCount) CDIndex = 0;
		return (CDDrives[CDIndex++]);
	}else{
		return (-1);
	}
}



/***************************************************************************
 * GCDC::Get_First_CD_Drive -- return the number of the first CD drive     *
 *                                                                         *
 *                                                                         *
 *                                                                         *
 * INPUT:                                                                  *
 *			none																				  *
 * OUTPUT:                                                                 *
 *			logical drive number 														  *
 * WARNINGS:                                                               *
 *                                                                         *
 * HISTORY:                                                                *
 *   05/26/1994 SW : Created.                                              *
 *   12/4/95    ST : fixed for Win95                                       *
 *=========================================================================*/
inline int GetCDClass::Get_First_CD_Drive(void)
{
	CDIndex = 0;
	return (Get_Next_CD_Drive());
}

/***************************************************************************
 * RedBookClass -- adds red book functionality										*
 *																									*
 *	this class inherits from GetCDClass and adds red book play functionality*
 *																									*
 *                                                                         *
 * HISTORY:                                                                *
 *   06/04/1994 SW : Created.																*
 *=========================================================================*/

class RedBookClass : public GetCDClass {

private:

	SEGSEL		Tinfo_addrp;
	SEGSEL		Stat_addrp;
	SEGSEL		Stop_addrp;
	SEGSEL		Volm_addrp;
	SEGSEL  	   Play_addrp;

	StopType 	Stop;
	PlayType		Play;
	VolmType		Volm;
	StatType		Stat;
	TinfoType	Tinfo;

public:

	RedBookClass(VOID);					// This is the default constructor
	~RedBookClass(VOID);					// This is the destructor

	ULONG	RedToHS(ULONG i);
	ULONG MSFtoRed(UBYTE m, UBYTE s, UBYTE f);
	VOID  FullCDVolume(UBYTE chan);
	VOID  PlayTrack(UWORD track);
	VOID  Play_CD_MSL(UWORD min_sec, UWORD len);
	VOID  PlayMSF(UBYTE startM, UBYTE startS, UBYTE startF, 
				UBYTE endM, UBYTE endS, UBYTE endF, UBYTE chan);
	UWORD CheckCDMusic(VOID);
	VOID  StopCDMusic(VOID);

};


/***************************** End of Playcd.h ****************************/

#endif // PLAYCD_H
