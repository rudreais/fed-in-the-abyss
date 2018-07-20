#include <ncurses.h>

int get_width(void)
{
	int width = COLS - 40;

	width = ((width % 2) == 0) ? width - 1 : width;
	return width;
}

int get_height(void)
{
	int height = LINES - 10;

    height = ((height % 2) == 0) ? height - 1 : height;
	return height;
}
