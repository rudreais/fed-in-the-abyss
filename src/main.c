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
    char c_char;

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
        c_char = map[pos->y][pos->x];
        if (c_char == possible_enemies[i].name || c_char == '@') {
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
	cursor_t *fixed = malloc(sizeof(cursor_t)); // fixed cam pos
    player_t *player = create_player();
    enemy_t **enemies = malloc(sizeof(enemy_t) * 10);
	int c = 0; // key pressed
	int border = 0; // define if fixed cam pos is used or not

	cursor_copy(fixed, player->pos); // between cursors
    add_enemy(enemies);
	while (c != 'q') {
		move_charac(c, player->pos, player->pos_bak, maps->files[0]->map);
		assign_player(maps->files[0]->map, old_state, player->pos, player->pos_bak);
		cursor_copy(player->pos_bak, player->pos);
        enemy_turn(enemies[0]);
        assign_enemy(maps->files[0]->map, old_state, enemies[0]);
		if ((border = border_cam(player->pos)) > 0) {
			if (border == 2 || border == 4) // border on left/right
				fixed->y = player->pos->y;
			if (border == 1 || border == 3) // border on top/bottom
				fixed->x = player->pos->x;
			centered_map(win, fixed, maps);
			refresh();
			wrefresh(win);
		} else {
			cursor_copy(fixed, player->pos_bak);
			centered_map(win, player->pos, maps);
		}
        wmove(win, 1, 1); // test purpose
        wprintw(win, "%d\t%d", player->pos->x, player->pos->y);
		refresh();
		wrefresh(win);
		c = getch();
	}
	free(player->pos);
	free(player->pos_bak);
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
    move(0, 0);
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
