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
#include "windows.h"
#include "character.h"
#include "generator.h"

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
		if (pos->y == -1 || pos->y == (first_floor->ymax - 1) ||
			pos->x == -1 ||	first_floor->design[pos->y][pos->x] == hard_tiles[i]) {
			pos->x = old_pos->x;
			pos->y = old_pos->y;
		}
	}
}

int main(void)
{
	cursor_t initial_pos = {0};
	cursor_t pos = {.x = 1, .y = 1};
	cursor_t old_pos;
	int c;
	dim_t size;
	WINDOW *main_win;
	tab_t main_tab;

	size.width = 46;
	size.height = 16;
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();
	main_win = create_window(&initial_pos, &size);
	main_tab.win = main_win;
	main_tab.initial_pos = &initial_pos;
	main_tab.size = &size;
	mvwprintw(main_tab.win, pos.y, pos.x, "@");
	wrefresh(main_tab.win);
	wmove(main_tab.win, 1, 1);
	while (c != 'q') {
		c = getch();
		move_char(&pos, &old_pos, c);
		mvwdelch(main_tab.win, old_pos.y, old_pos.x);
		print_window(&main_tab, &pos);
	}
	endwin();
}

/*
get_map(&first_floor);
startxy = get_start(&first_floor);
print_map(&first_floor, &startxy);
pos = startxy;
mvprintw(27, 0, "%d\n", first_floor.ymax);
while (c != 'q') {
	c = getch();
	move_char(&pos, &old_pos, c);
	collision(&pos, &old_pos, &first_floor);
	print_map(&first_floor, &pos);
	mvprintw(25, 0, "%d | %d\n", pos.x, pos.y);
	mvprintw(26, 0, "%d | %d\n", COLS, LINES);
	refresh();
}
*/