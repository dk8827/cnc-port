#include "../CODE/FUNCTION.H"

#include <stdio.h>

static int fail(char const *message)
{
	fprintf(stderr, "FAIL: %s\n", message);
	return 1;
}

int main(void)
{
	for (int direction = 0; direction < 256; ++direction) {
		DirType canonical = (DirType)direction;
		DirType sign_extended = (DirType)(signed char)direction;
		DirType previous_turn = (DirType)(direction - 256);
		DirType next_turn = (DirType)(direction + 256);
		if (Facing_To_32(canonical) != Facing_To_32(sign_extended) ||
			Facing_To_32(canonical) != Facing_To_32(previous_turn) ||
			Facing_To_32(canonical) != Facing_To_32(next_turn)) {
			return fail("32-way sprite facing must use the low direction byte");
		}
	}

	for (int current = 0; current < 256; ++current) {
		for (int rate = 1; rate <= 127; ++rate) {
			DirType clockwise = (DirType)current + rate;
			DirType counter_clockwise = (DirType)current - rate;
			if ((int)clockwise != ((current + rate) & 0xff)) {
				return fail("clockwise facings must wrap through north");
			}
			if ((int)counter_clockwise != ((current - rate) & 0xff)) {
				return fail("counter-clockwise facings must wrap through north");
			}
		}
	}
	return 0;
}
