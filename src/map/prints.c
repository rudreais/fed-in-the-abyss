/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** prints function for map
*/

#include <ncurses.h>
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