/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "windows.h"
#include "generator.h"

void move_char(cursor_t *pos, cursor_t *old_pos, int c)
{
	old_pos->x = pos->x;
	old_pos->y = pos->y;
	switch (c) {
		case KEY_DOWN:
			pos->y++;
			break;
		case KEY_UP:
			pos->y--;
			break;
		case KEY_LEFT:
			pos->x--;
			break;
		case KEY_RIGHT:
			pos->x++;
			break;
		default:
			break;
	}
}

void collision(cursor_t *pos, cursor_t *old_pos, floor_t *first_floor)
{
	for (int i = 0; hard_tiles[i]; i++) {
		if (pos->y == -1 || (pos->y - 1) == (first_floor->ymax - 1) ||
			pos->x == -1 ||	first_floor->design[pos->y][pos->x] == hard_tiles[i]) {
			pos->x = old_pos->x;
			pos->y = old_pos->y;
		}
	}
}

void collision_win(cursor_t *pos, cursor_t *old_pos, floor_t *f_floor)
{
	for (int i = 0; hard_tiles[i]; i++) {
		if (pos->y == f_floor->ymax ||
			((pos->y > 0 && pos->x > 0) && f_floor->design[pos->y - 1][pos->x - 1] == hard_tiles[i]) || 
			(pos->y == 0 || pos->x == 0)) {
				mvprintw(40, 0, "DEBUG NEXT HIT\ny=%d x=%d ymax=%d\n", pos->y, pos->x, f_floor->ymax);
			pos->x = old_pos->x;
			pos->y = old_pos->y;
		}
	}
}

int main(void)
{
	cursor_t initial_pos = {.x = 20, .y = 0};
	cursor_t pos = {.x = 1, .y = 1};
	cursor_t map_pos = {.x = 15, .y = 5};
	cursor_t old_pos;
	int c;
	dim_t size;
	tab_t main_tab;
	floor_t f_floor;

	get_map(&f_floor);
	pos = get_start(&f_floor);
	pos.y++;
	pos.x++;
	size.width = 80;
	size.height = 30;
	init_curse();
	init_tab(&main_tab, &initial_pos, &size);
	mvwprintw(main_tab.win, pos.y, pos.x, "@");
	wrefresh(main_tab.win);
	wmove(main_tab.win, 1, 1);
	while (c != 'q') {
		wclear(main_tab.win);
		print_map_window(&main_tab, &f_floor, &map_pos, &pos);
		print_window(&main_tab, &pos);
		c = getch();
		move_char(&pos, &old_pos, c);
		mvwdelch(main_tab.win, old_pos.y, old_pos.x);
		collision_win(&pos, &old_pos, &f_floor);
		mvprintw(38, 0, "DEBUG ABSOLUTE POS\ny=%d x=%d\n", map_pos.y + pos.y, map_pos.x + pos.x);
		mvprintw(42, 0, "DEBUG ACTUAL POS\ny=%d x=%d\n", pos.y, pos.x);
	}
	endwin();
}