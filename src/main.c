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
#include "files.h"

//extern char **environ;

void init_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}

void loop(void)
{
	WINDOW *win = newwin(30, 70, 5, 5);
	files_t *maps = malloc(sizeof(files_t));

	files_init(maps, getpath("maps"));
}

int main(void)
{
	//	init_curses();
	//	loop();
	//	endwin();
	return 0;
}
