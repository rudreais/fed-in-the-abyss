/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** map generator header
*/

#include <ncurses.h>
#include "character.h"
#include "windows.h"

WINDOW *create_window(cursor_t *pos, dim_t *size)
{
	WINDOW *new_win;

    new_win = newwin(size->height, size->width, pos->y, pos->x);
	box(new_win, 0, 0);
	return new_win;
}