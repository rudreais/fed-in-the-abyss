/**
 ** rudreais
 ** main
 **
 */

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

void move_charac(int key, Cursor *pos)
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

char **cpy_state(file_t *map)
{
	char **old_state = malloc(sizeof(char *) * map->y_len);
	int length = 0;

	for (int i = 0; i < map->y_len; i++) {
		length = strlen(map->map[i]);
		old_state[i] = malloc(sizeof(char) * (length + 1));
		old_state[i][length] = '\0';
		strcpy(old_state[i], map->map[i]);
	}
	return old_state;
}

void assign_player(char **map, char **old_state, Cursor *charac, Cursor *cam)
{
	map[cam->y][cam->x] = old_state[cam->y][cam->x];
	map[charac->y][charac->x] = '@';
}

int border_cam(Cursor *cam)
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
	Cursor *charac = malloc(sizeof(Cursor));
	Cursor *cam = malloc(sizeof(Cursor));
	Cursor *fixed = malloc(sizeof(Cursor));
	int c = 0;
	int border = 0;

	charac->init = CursorInit;	// player position
	cam->init = CursorInit;	// backup camera
	fixed->init = CursorInit;
	charac->init(charac, (width / 2) + 1, (height / 2) + 1);
    cam->init(cam, (width / 2) + 1, (height / 2) + 1);
    fixed->init(fixed, (width / 2) + 1, (height / 2) + 1);

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
}

void start_level(int level)
{
	files_t *maps = malloc(sizeof(files_t));
	char **old_state = NULL;

	(void)level;
	files_init(maps, getpath("maps"));
	old_state = cpy_state(maps->files[0]);
	//	gen_map(level);
	init_curses();
	loop(maps, old_state);//win, maps);
	endwin();
}

int main(void)
{
	start_level(1);
	return 0;
}
