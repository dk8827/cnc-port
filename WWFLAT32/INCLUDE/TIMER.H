/*
 * Copyright 2025 Electronic Arts Inc.
 *
 * Derived from Electronic Arts Inc.'s public source release for
 * Command & Conquer: Red Alert.
 * Licensed under GPLv3-or-later with additional Electronic Arts terms.
 * Modified for the macOS port, 2026.
 * See LICENSE.md.
 */

#ifndef TIMER_H
#define TIMER_H

/*=========================================================================*/
/* The following prototypes are for the file: TIMERA.ASM							*/
/*=========================================================================*/

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// Externs /////////////////////////////////////////////
extern BOOL TimerSystemOn;


/*=========================================================================*/
typedef enum BaseTimerEnum {
	BT_SYSTEM,			// System timer (60 / second).
	BT_USER				// User controllable timer (? / second).
} BaseTimerEnum;

class TimerClass {
 	public:
		// Constructor.  Timers set before low level init has been done will not
		// be able to be 'Started' or 'on' until timer system is in place.
		TimerClass(BaseTimerEnum timer=BT_SYSTEM, BOOL start=FALSE);

		// No destructor.
		~TimerClass(void){}

		//
		long Set(long value, BOOL start=TRUE);	// Set initial timer value.
		long Stop(void);				// Pause timer.
		long Start(void);				// Resume timer.
		long Reset(BOOL start=TRUE);	// Reset timer to zero.
		long Time(void);				// Fetch current timer value.

	protected:
		long Started;					// Time last started (0 == not paused).
		long Accumulated;				//	Total accumulated ticks.

	private:
		long (*Get_Ticks)(void);	// System timer fetch.
};


inline long TimerClass::Reset(BOOL start)
{
	return(Set(0, start));
}


//lint -esym(1509,TimerClass)
class CountDownTimerClass : private TimerClass {
	public:
		// Constructor.  Timers set before low level init has been done will not
		// be able to be 'Started' or 'on' until timer system is in place.
		CountDownTimerClass(BaseTimerEnum timer, long set, int on=FALSE);
		CountDownTimerClass(BaseTimerEnum timer=BT_SYSTEM, int on=FALSE);

		// No destructor.
		~CountDownTimerClass(void){}

		// Public functions
		long Set(long set, BOOL start=TRUE);	// Set count down value.
		long Reset(BOOL start=TRUE);	// Reset timer to zero.
		long Stop(void);			// Pause timer.
		long Start(void);			// Resume timer.
		long Time(void);			// Fetch current count down value.

	protected:
		long DelayTime;			// Ticks remaining before countdown timer expires.
};

inline long CountDownTimerClass::Stop(void)
{
	TimerClass::Stop();
	return(Time());
}

inline long CountDownTimerClass::Start(void)
{
	TimerClass::Start();
	return(Time());
}

inline long CountDownTimerClass::Reset(BOOL start)
{
	return (TimerClass::Reset(start));
}



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// externs  //////////////////////////////////////////

//extern TimerClass					TickCount;
extern CountDownTimerClass		CountDown;

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////// Prototypes //////////////////////////////////////////

extern "C" {
	long Get_System_Tick_Count(void);
	long Get_User_Tick_Count(void);
	void far Timer_Interrupt_Func(void);
//	long Get_Num_Interrupts(unsigned int realmode);
	void Disable_Timer_Interrupt(void);
	void Enable_Timer_Interrupt(void);
}

/*=========================================================================*/
/* The following prototypes are for the file: TIMER.CPP							*/
/*=========================================================================*/
BOOL Init_Timer_System(unsigned int freq, int partial = FALSE);
BOOL Remove_Timer_System(VOID);


#endif // TIMER_H


