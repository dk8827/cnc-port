#include "../CODE/FUNCTION.H"

#include <stdio.h>

int calcx(signed short value, short distance)
{
	return (int)value * distance;
}

int calcy(signed short value, short distance)
{
	return (int)value * distance;
}

static int expect_equal(short actual, short expected, char const *label)
{
	if (actual != expected) {
		fprintf(stderr, "FAIL: %s: got %d, expected %d\n", label, actual, expected);
		return 1;
	}
	return 0;
}

int main()
{
	short expected_x = 100;
	short expected_y = 100;
	short wrapped_x = 100;
	short wrapped_y = 100;
	volatile unsigned int invalid_direction = 0xffffff40U;

	Move_Point(expected_x, expected_y, DIR_E, 1);
	Move_Point(wrapped_x, wrapped_y, (DirType)invalid_direction, 1);

	if (expect_equal(wrapped_x, expected_x, "wrapped direction x")) return 1;
	if (expect_equal(wrapped_y, expected_y, "wrapped direction y")) return 1;
	return 0;
}
