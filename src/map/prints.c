/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** prints function for map
*/

#include <ncurses.h>
#include "board.h"

/*
void print_window(tab_t *tab)
{
	box(tab->win, 0, 0);
	wrefresh(tab->win);
}

void print_map_window(tab_t *tab, floor_t *f_floor, cursor_t *map_pos, cursor_t *pos)
{
	for (int i = 0; i < f_floor->ymax - 1; i++) {
		wmove(tab->win, map_pos->y + i, map_pos->x);
		wprintw(tab->win, "%s", f_floor->design[i]);
	}
	mvwprintw(tab->win, (map_pos->y - 1) + pos->y, (map_pos->x - 1) + pos->x, "@");
}

void debug_map(char **map, int ymax)
{
	for (int i = 0; i < ymax; i++)
		printf("%s", map[i]);
}
*/

void print_tab();

void print_game()
{

}