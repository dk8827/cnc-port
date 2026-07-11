#include "../CODE/FUNCTION.H"

#include <stdlib.h>

#define ICON_PIXEL_W 24
#define ICON_LEPTON_W 256
#define CELL_LEPTON_W ICON_LEPTON_W
#define ARRAY_SIZE(x) int(sizeof(x) / sizeof((x)[0]))

#include <stdio.h>

static int fail(char const *message)
{
	fprintf(stderr, "FAIL: %s\n", message);
	return 1;
}

static int expect_int(int actual, int expected, char const *message)
{
	if (actual != expected) {
		fprintf(stderr, "FAIL: %s: got %d expected %d\n", message, actual, expected);
		return 1;
	}
	return 0;
}

int main(void)
{
	COORDINATE crash_coord = 0x00cf012fUL;
	if (expect_int(Coord_XCell(crash_coord), 1, "diagnostic crash coordinate x cell")) return 1;
	if (expect_int(Coord_YCell(crash_coord), 0, "diagnostic crash coordinate y cell")) return 1;
	if (expect_int(Coord_XLepton(crash_coord), 0x2f, "diagnostic crash coordinate x lepton")) return 1;
	if (expect_int(Coord_YLepton(crash_coord), 0xcf, "diagnostic crash coordinate y lepton")) return 1;

	for (int y = 0; y < MAP_CELL_H; y += 17) {
		for (int x = 0; x < MAP_CELL_W; x += 19) {
			CELL cell = XY_Cell(x, y);
			COORDINATE coord = Cell_Coord(cell);
			if (expect_int(Cell_X(cell), x, "cell x round trip")) return 1;
			if (expect_int(Cell_Y(cell), y, "cell y round trip")) return 1;
			if (expect_int(Coord_XLepton(coord), CELL_LEPTON_W / 2, "cell coord x center")) return 1;
			if (expect_int(Coord_YLepton(coord), CELL_LEPTON_W / 2, "cell coord y center")) return 1;
		}
	}

	return 0;
}
