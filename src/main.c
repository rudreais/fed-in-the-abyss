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
#include "character.h"
#include "generator.h"

void update_pos(cursor_t *pos, cursor_t *old_pos)
{
	mvdelch(old_pos->y, old_pos->x);
	mvprintw(pos->y, pos->x, "@");
}

int main(void)
{
	cursor_t pos, old_pos;
	int c;
	char *path = "../../../maps/1_1";
	FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

	fp = fopen(path, "r");
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	while (read = getline(&line, &len, fp) != -1) {
		printw("%s", line);
	}
	pos.x = COLS / 2;
	pos.y = LINES / 2;
	mvprintw(pos.y, pos.x, "@");
	while (c != 'q') {
		switch (c) {
			case KEY_DOWN:
				pos.y++;
				break;
			case KEY_UP:
				pos.y--;
				break;
			case KEY_LEFT:
				pos.x--;
				break;
			case KEY_RIGHT:
				pos.x++;
				break;
			default:
				break;
		}
		update_pos(&pos, &old_pos);
		old_pos = pos;
		c = getch();
		mvprintw(25, 0, "%d | %d\n", pos.x, pos.y);
		mvprintw(26, 0, "%d | %d\n", COLS, LINES);
		refresh();
	}
	endwin();
}