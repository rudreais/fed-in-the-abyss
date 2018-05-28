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
#include "character.h"
#include "generator.h"

cursor_t get_start(floor_t *f_floor)
{
	cursor_t startxy = {0};

	for (int i = 0; i < f_floor->ymax - 1; i++) {
		for (int j = 0; f_floor->design[i][j]; j++) {
			if (f_floor->design[i][j] == '*') {
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
	char *path = "../../../maps/1_1";
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
	int i = 1;

	f_floor->design = malloc(sizeof(char *) * 1);
	fp = fopen(path, "r");
	while (read = getline(&line, &len, fp) != -1) {
		f_floor->design = realloc(f_floor->design, sizeof(char *) * i + 1);
		f_floor->design[i - 1] = strdup(line);
		i++;
	}
	f_floor->design[i] = NULL;
	f_floor->ymax = i;
}

void print_map(floor_t *f_floor, cursor_t *pos)
{
	move(0, 0);
	for (int i = 0; i < f_floor->ymax - 1; i++) {
		printw("%s", f_floor->design[i]);
	}
	mvprintw(pos->y, pos->x, "@");
}

void move_char(cursor_t *pos, int c)
{
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

int main(void)
{
	cursor_t pos, old_pos;
	cursor_t startxy;
	floor_t first_floor;
	int c;
	cursor_t initial_pos = {0};

	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	get_map(&first_floor);
	startxy = get_start(&first_floor);
	print_map(&first_floor, &startxy);
	pos = startxy;
	while (c != 'q') {
		c = getch();
		move_char(&pos, c);
		old_pos = pos;
		print_map(&first_floor, &pos);
		mvprintw(25, 0, "%d | %d\n", startxy.x, startxy.y);
		mvprintw(26, 0, "%d | %d\n", COLS, LINES);
		refresh();
	}
	endwin();
}