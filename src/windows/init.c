/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** map generator header
*/

#include <ncurses.h>
#include <stdlib.h>
#include "board.h"

cursor_t get_start(floor_t *f_floor)
{
	cursor_t startxy = {0};

	for (int i = 0; i < f_floor->ymax - 1; i++) {
		for (int j = 0; f_floor->design[i][j]; j++) {
			if (f_floor->design[i][j] == START_FLOOR) {
				startxy.x = j;
				startxy.y = i;
				mvprintw(28,0,"%d %d\n", j, i);
			}
		}
	}
	return startxy;
}

void get_map(floor_t *f_floor)
{
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int i = 1;

	f_floor->design = malloc(sizeof(char *) * 1);
	fp = fopen((PATH), "r");
	while ((read = getline(&line, &len, fp)) != -1) {
		f_floor->design = realloc(f_floor->design, sizeof(char *) * i + 1);
		f_floor->design[i - 1] = strdup(line);
		i++;
	}
	f_floor->design[i] = NULL;
	f_floor->ymax = i;
}

void init_tab(tab_t *tab, cursor_t *pos, dim_t *size)
{
	WINDOW *new_win;

    new_win = newwin(size->height, size->width, pos->y, pos->x);
	box(new_win, 0, 0);
	tab->win = new_win;
	tab->initial_pos = pos;
	tab->size = size;
}

void init_curse(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();
}