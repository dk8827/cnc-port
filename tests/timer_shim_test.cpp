#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static volatile int CallbackCount = 0;

static void CALLBACK timer_callback(UINT, UINT, DWORD, DWORD, DWORD)
{
	++CallbackCount;
}

static void fail(char const *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

int main()
{
	MMRESULT timer = timeSetEvent(10, 1, timer_callback, 0, TIME_PERIODIC);
	if (timer == 0) fail("timeSetEvent returned zero");

	for (int index = 0; index < 6; ++index) {
		usleep(10000);
		MacMM_PumpTimers();
	}
	timeKillEvent(timer);

	if (CallbackCount < 2) fail("timer callback did not fire");
	return 0;
}
