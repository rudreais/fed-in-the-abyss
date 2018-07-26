/**
 ** rudreais
 ** main
 **
 */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "o_strings.h"
#include "cursor.h"
#include "fita.h"
#include "path.h"
#include "files.h"

void init_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
}

void move_charac(int key, cursor_t *pos)
{
	switch (key) {
	case KEY_LEFT:
		pos->x--;
		break;
	case KEY_RIGHT:
		pos->x++;
		break;
	case KEY_UP:
		pos->y--;
		break;
	case KEY_DOWN:
		pos->y++;
		break;
	default:
		break;
	}
	pos->x = (pos->x < 0) ? 0 : pos->x;
	pos->x = (pos->x > 511) ? 511 : pos->x;
	pos->y = (pos->y < 0) ? 0 : pos->y;
	pos->y = (pos->y > 511) ? 511 : pos->y;
}

int border_cam(cursor_t *cam)
{
	int width = get_width();
	int height = get_height();

	if ((cam->x < ((width / 2) + 1) && cam->y < ((height / 2) + 1)) ||
		(cam->x < ((width / 2) + 1) && cam->y > 512 - (height / 2)) ||
		(cam->x > 512 - (width / 2) && cam->y < ((height / 2) + 1)) ||
		(cam->x > 512 - (width / 2) && cam->y > 512 - (height / 2)))
		return 5;
	if (cam->x < ((width / 2) + 1))
		return 4;
	if (cam->x > 512 - (width / 2))
		return 2;
	if (cam->y < ((height / 2) + 1))
		return 1;
	if (cam->y > 512 - (height / 2))
		return 3;
	return 0;
}

void loop(files_t *maps, char **old_state)
{
	int width = get_width();
	int height = get_height();
	WINDOW *win = newwin(height, width, 0, 0);
	cursor_t *charac = malloc(sizeof(cursor_t));
	cursor_t *cam = malloc(sizeof(cursor_t));
	cursor_t *fixed = malloc(sizeof(cursor_t));
	int c = 0;
	int border = 0;

	cursor_modify(charac, (width / 2) + 1, (height / 2) + 1);
	cursor_copy(cam, charac);
	cursor_copy(fixed, charac);

	while (c != 'q') {
		move_charac(c, charac);
		assign_player(maps->files[0]->map, old_state, charac, cam);
		cursor_copy(cam, charac);
		if ((border = border_cam(charac)) > 0) {
			if (border == 2 || border == 4) // border on left/right
				fixed->y = cam->y;
			if (border == 1 || border == 3)
				fixed->x = cam->x;
			centered_map(win, fixed, maps);
			wmove(win, 1, 1);
			wprintw(win, "%d\t%d", charac->x, charac->y);
			refresh();
			wrefresh(win);
		} else {
			cursor_copy(fixed, cam);
			centered_map(win, charac, maps);
		}
		refresh();
		wrefresh(win);
		c = getch();
	}
	free(charac);
	free(cam);
	free(fixed);
	delwin(win);
}

void destroy_files(files_t *files)
{
	for (int i = 0; i < files->size; i++) {
		for (int j = 0; j < files->files[i]->y_len; j++) {
			free(files->files[i]->map[j]);
		}
		free(files->files[i]->map);
		free(files->files[i]->name);
	}
}

void start_level(void)
{
	files_t *maps = malloc(sizeof(files_t));
	char **old_state = NULL;
	char *path = getpath("maps");

	files_init(maps, path);
	old_state = cpy_state(maps->files[0]);
	for (int i = 0; i < 7; i++) {
		gen_map(i + 1);
		sleep(1);
	}
	init_curses();
	loop(maps, old_state);//win, maps);
	endwin();
	for (int i = 0; i < 512; i++)
		free(old_state[i]);
	free(old_state);
	destroy_files(maps);
	free(maps);
	free(path);
}

int main(void)
{
	start_level();
	return 0;
}
