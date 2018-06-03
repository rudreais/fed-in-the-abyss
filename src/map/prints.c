/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** prints function for map
*/

#include <ncurses.h>
#include "board.h"
#include "windows.h"

/*
void print_window(tab_t *tab)
{
	box(tab->win, 0, 0);
	wrefresh(tab->win);
}

void print_map_window(tab_t *tab, floor_t *f_floor, cursor_t *map_pos, cursor_t *pos)
{
}
*/

void print_tab(WINDOW *win)
{
	box(win, 0, 0);
	wrefresh(win);
}

cursor_t *get_cursor(floor_t *f_floor)
{
	cursor_t *tmp;

	if (f_floor->chars[0]->appear == '@')
		tmp = f_floor->chars[0]->pos;
	return tmp;
}

void print_map(dungeon_t *abyss, WINDOW *win)
{
	cursor_t *map_pos = get_cursor(abyss->floors[0]);

	for (int i = 0; i < abyss->floors[0]->ymax; i++) {
		mvwprintw(win, map_pos->y + i, map_pos->x,"%s", abyss->floors[0]->design[i]);
	}
}

void print_game(dungeon_t *abyss, tab_t **tabs)
{
	print_map(abyss, tabs[0]->win);
	print_tab(tabs[0]->win);
}