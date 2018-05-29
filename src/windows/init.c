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

	f_floor->design = calloc(1, sizeof(char *));
	fp = fopen((PATH), "r");
	while ((read = getline(&line, &len, fp)) != -1) {
		f_floor->design = realloc(f_floor->design, sizeof(char *) * (i + 1));
		f_floor->design[i - 1] = strdup(line);
		i++;
	}
	f_floor->design[i - 1] = NULL;
	f_floor->ymax = i - 1;
}

void init_dungeon(dungeon_t *dungeon)
{
	dungeon->floors = malloc(sizeof(floor_t *) * 1);
	dungeon->floors[0] = malloc(sizeof(floor_t));
	dungeon->floors[0]->design = calloc(1, sizeof(char *));
	get_map(dungeon->floors[0]);
}

void init_tabs(tab_t **tabs)
{
	tab_t *game = malloc(sizeof(tab_t));
	
	tabs[0] = game;
	tabs[0]->win = malloc(sizeof(WINDOW *));
	tabs[0]->tab_pos = malloc(sizeof(cursor_t));
	tabs[0]->tab_size = malloc(sizeof(dim_t));
}

void init_curse(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();
}