//
// Created by rudreais on 16/07/18.
//

#include <ncurses.h>
#include "fita.h"

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
	case '@':
		wattron(win, A_BOLD);
		wprintw(win, "@");
		wattroff(win, A_BOLD);
		break;
	default:
		wprintw(win, "%c", c);
		break;
	}
}

void centered_map(WINDOW *win, cursor_t *cam, map_t **maps)
{
	map_t *map = maps[0];
	int cam_i = (cam->y - (N_LINES / 2)) - 1;
	int cam_j = (cam->x - (N_COLS / 2)) - 1;

		cam_i = (cam_i < 0) ? 0 : cam_i;
		cam_j = (cam_j < 0) ? 0 : cam_j;
	for (int i = 0; i < N_LINES; i++) {
		for (int j = 0; j < N_COLS; j++) {
			wmove(win, i, j);
			print_char(win, map->map[i + cam_i][j + cam_j]);
		}
	}
	refresh();
	wrefresh(win);
}
