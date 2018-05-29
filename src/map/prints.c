/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** prints function for map
*/

#include <ncurses.h>
#include "windows.h"
#include "character.h"
#include "generator.h"

void print_map(floor_t *f_floor, cursor_t *pos)
{
	move(0, 0);
	for (int i = 0; i < f_floor->ymax - 1; i++) {
		printw("%s", f_floor->design[i]);
	}
	mvprintw(pos->y, pos->x, "@");
}

void print_window(tab_t *tab, cursor_t *pos)
{
	wmove(tab->win, 1, 1);
	mvwprintw(tab->win, pos->y, pos->x, "@");
	box(tab->win, 0, 0);
	wrefresh(tab->win);
}

void print_map_window(tab_t *tab, floor_t *f_floor, cursor_t *pos)
{
	for (int i = 0; i < f_floor->ymax - 1; i++) {
		wmove(tab->win, i+1, 1);
		wprintw(tab->win, "%s", f_floor->design[i]);
	}
	mvwprintw(tab->win, pos->y, pos->x, "@");
}