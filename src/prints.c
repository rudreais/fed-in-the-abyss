//
// Created by rudreais on 16/07/18.
//

#include <ncurses.h>
#include "files.h"

void print_char(char c)
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	switch (c) {
	case '~':
		attron(COLOR_PAIR(1));
		printw("%c", c);
		attroff(COLOR_PAIR(1));
		break;
	case '.':
		attron(COLOR_PAIR(2));
		printw("%c", c);
		attroff(COLOR_PAIR(2));
		break;
	case '%':
		attron(COLOR_PAIR(3));
		printw("%c", c);
		attroff(COLOR_PAIR(3));
		break;
	default:
		printw("%c", c);
		break;
	}
}

void print_map(WINDOW *win, files_t *maps)
{
	for (int i = 0; i < 55; i++) {
		for (int j = 0; j < 160; j++)
			print_char(maps->files[0]->map[i][j]);
		printw("\n");
	}
}
