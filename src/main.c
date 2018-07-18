/**
 ** rudreais
 ** main
 **
 */

#include  <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "o_strings.h"
#include "cursor.h"
#include "fita.h"
#include "path.h"
#include "files.h"

void init_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}

int get_width(void)
{
	int width = COLS - 40;

	width = ((width % 2) == 0) ? width-- : width;
	return width;
}

int get_height(void)
{
	int height = LINES - 10;

    height = ((height % 2) == 0) ? height-- : height;
	return height;
}

void camera_attr(Cursor *cam, int key)
{
	switch (key) {
	case KEY_LEFT:
		cam->x--;
		break;
	case KEY_RIGHT:
		cam->x++;
		break;
	case KEY_UP:
		cam->y--;
		break;
	case KEY_DOWN:
		cam->y++;
		break;
	}
}

void loop(void)
{
	int width = get_width();
	int height = get_height();
	WINDOW *win = newwin(height, width, 0, 0);
	files_t *maps = malloc(sizeof(files_t));
	Cursor *charac = malloc(sizeof(Cursor));
	int c = 0;

    charac->init = CursorInit;
	charac->init(cam, (width / 2) + 1, (height / 2) + 1);
	files_init(maps, getpath("maps"));
	print_map(win, cam, maps);
	while (c != 'q') {
		c = getch();
		camera_attr(charac, c);
		print_map(win, charac, maps);
	}
}

void start_level(int level)
{
	//	gen_map(level);
	init_curses();
	loop();
	endwin();
}

int main(void)
{
	start_level(1);
	return 0;
}
