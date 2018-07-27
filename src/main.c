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
#include "enemy.h"

static int FAST_RUN = 0;

extern enemy_t possible_enemies[];

void init_curses(void)
{
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
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

void move_charac(int key, cursor_t *pos, cursor_t *cam, char **map)
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
    for (int i = 0; possible_enemies[i].name; i++) {
        if (map[pos->y][pos->x] == possible_enemies[i].name) {
            pos->x = cam->x;
            pos->y = cam->y;
            return;
        }
    }
}

void loop(files_t *maps, char **old_state)
{
	int width = get_width();
	int height = get_height();
	WINDOW *win = newwin(height, width, 0, 0);
	cursor_t *charac = malloc(sizeof(cursor_t));
	cursor_t *cam = malloc(sizeof(cursor_t));
	cursor_t *fixed = malloc(sizeof(cursor_t));
    enemy_t **enemies = malloc(sizeof(enemy_t) * 10);
	int c = 0;
	int border = 0;

	cursor_modify(charac, (width / 2) + 1, (height / 2) + 1);
	cursor_copy(cam, charac);
	cursor_copy(fixed, charac);
    add_enemy(maps, enemies);
	while (c != 'q') {
		move_charac(c, charac, cam, maps->files[0]->map);
		assign_player(maps->files[0]->map, old_state, charac, cam);
		cursor_copy(cam, charac);
		if ((border = border_cam(charac)) > 0) {
			if (border == 2 || border == 4) // border on left/right
				fixed->y = cam->y;
			if (border == 1 || border == 3)
				fixed->x = cam->x;
			centered_map(win, fixed, maps);
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

void start_level(void)
{
	files_t *maps = malloc(sizeof(files_t));
	char **old_state = NULL;
	char *path = getpath("maps");

	files_init(maps, path);
	old_state = cpy_state(maps->files[0]);
    if (FAST_RUN == 1) {
        for (int i = 0; i < 7; i++) {
            gen_map(i + 1);
            sleep(1);
        }
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

int main(int ac, char **av)
{
    if (ac > 1) {
        if (av[1][0] == '1') {
            FAST_RUN = 1;
        }
    }
	start_level();
	return 0;
}
