/**
 ** rudreais
 ** main
 **
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "o_strings.h"
#include "cursor.h"
#include "fita.h"
#include "path.h"
#include "maps.h"

void init_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
}

void loop(void)
{
	WINDOW *win = newwin(30, 70, 5, 5);
	Cursor cam_ini;
	files_t *files = malloc(sizeof(files_t));

	files_init(files, getpath("maps"));
	printw("%d\n", files->size);
	cam_ini.init = CursorInit;
	cam_ini.init(&cam_ini, 1, 1); // starting at the very top left

	box(win, 0, 0);
	refresh();
	wrefresh(win);
	getch();
}

int main(void)
{
	init_curses();
	loop();
	endwin();
	return 0;
}
