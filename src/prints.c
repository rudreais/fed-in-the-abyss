//
// Created by rudreais on 16/07/18.
//

#include <ncurses.h>
#include "cursor.h"
#include "files.h"

void print_char(WINDOW *win, char c)
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	switch (c) {
	case '~':
		wattron(win, COLOR_PAIR(1));
		wprintw(win, "%c", c);
		wattroff(win, COLOR_PAIR(1));
		break;
	case '.':
		wattron(win, COLOR_PAIR(2));
		wprintw(win, "%c", c);
		wattroff(win, COLOR_PAIR(2));
		break;
	case '%':
		wattron(win, COLOR_PAIR(3));
		wprintw(win, "%c", c);
		wattroff(win, COLOR_PAIR(3));
		break;
	default:
		wprintw(win, "%c", c);
		break;
	}
}

void print_map(WINDOW *win, Cursor *cam, files_t *maps)
{
	file_t *map = maps->files[0];
	int cam_i = (cam->y - ((LINES - 10) / 2)) - 1;
	int cam_j = (cam->x - ((COLS - 40) / 2)) - 1;

	for (int i = 0; i < ((LINES - 10) - 1); i++) {
		for (int j = 0; j < ((COLS - 40) - 1); j++) {
			wmove(win, i, j);
			print_char(win, map->map[i + cam_i][j + cam_j]);
		}
	}
	wattron(win, A_BOLD);
	mvwprintw(win, (((LINES - 10) / 2) + 1), (((COLS - 40) / 2) + 1), "@");
	wattroff(win, A_BOLD);
	box(win, 0, 0);
	refresh();
	wrefresh(win);
}
