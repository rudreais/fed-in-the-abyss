#include <ncurses.h>
#include "fita.h"

int get_width(void)
{
	int width = N_COLS;

	width = ((width % 2) == 0) ? width - 1 : width;
	return width;
}

int get_height(void)
{
	int height = N_LINES;

    height = ((height % 2) == 0) ? height - 1 : height;
	return height;
}
