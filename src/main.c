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

static int FAST_RUN = 1;

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
	int width = GET_WIDTH;
	int height = GET_HEIGHT;

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

cursor_t *move_charac(int key, cursor_t *pos, cursor_t *cam, char **map)
{
    char c_char;
    cursor_t *ret = malloc(sizeof(cursor_t));

    ret->x = -1;
    ret->y = -1;
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
	    ret->x = pos->x;
	    ret->y = pos->y;
	    pos->x = cam->x;
	    pos->y = cam->y;
	    return ret;
	}
    }
    return ret;
}

// enemy_t turn => see include/enemy.h for details
void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player)
{
    int is_player = -1;
    cursor_t backup = {
	    .x = defender->x,
	    .y = defender->y
    };

    if (turn->name != '@')
		is_player = 0;
    else
        is_player = 1;
    if (is_player == 1) {
	for (int i = 0; enemies[i]; i++) {
	    if (enemies[i]->pos.x == backup.x &&
		enemies[i]->pos.y == backup.y) {
		enemies[i]->charac.hp = enemies[i]->charac.hp - turn->charac.str;
	    }
	}
    } else {
        player->charac.hp--;
    }
}

void loop(files_t *maps, char **old_state)
{
	WINDOW *win = newwin(GET_HEIGHT, GET_WIDTH, 0, 0);
	cursor_t fixed;
	player_t player;
	enemy_t **enemies = malloc(sizeof(enemy_t) * 10);
	int c = 0; // key pressed
	int border = 0; // define if fixed cam pos is used or not
	cursor_t *enemy_pos;

	create_player(&player);
	fixed = player.pos;
	add_enemy(enemies);
	while (c != 'q') {
		enemy_pos = move_charac(c, &player.pos, &player.pos_bak, maps->files[0]->map);
		assign_player(maps->files[0]->map, old_state, &player.pos, &player.pos_bak);
		player.pos_bak = player.pos;
		enemy_turn(&player, enemies[0], maps->files[0]->map, enemies, old_state);
		if (player.charac.hp <= 0) {
			screen_death();
			return;
		}
		assign_enemy(maps->files[0]->map, old_state, enemies[0]);
	        // if an enemy is killed, the player disappear
		assign_player(maps->files[0]->map,old_state,&player.pos,&player.pos_bak);
		if (enemy_pos->x != -1 && enemy_pos->y != -1)
		         attack(enemies, enemy_pos, &player, &player);
		if ((border = border_cam(&player.pos)) > 0) {
			if (border == 2 || border == 4) // border on left/right
				fixed.y = player.pos.y;
			if (border == 1 || border == 3) // border on top/bottom
				fixed.x = player.pos.x;
			centered_map(win, &fixed, maps);
			refresh();
			wrefresh(win);
		} else {
			fixed = player.pos_bak;
			centered_map(win, &player.pos, maps);
		}
		wmove(win, 1, 1); // test purpose
		wprintw(win, "%d", enemies[0]->charac.hp);
		wprintw(win, "\t%d\t%d", enemy_pos->x, enemy_pos->y);

        screen_charac(&player);
        screen_logs();
		refresh();
		wrefresh(win);
		c = getch();
	}
	delwin(win);
}

void start_level(void)
{
	files_t maps;
	char **old_state = NULL;
	char *path = getpath("maps");

	if (FAST_RUN == 1) {
		for (int i = 0; i < 7; i++) {
			gen_map(i + 1);
			sleep(1);
		}
	}
	files_init(&maps, path);
	old_state = cpy_state(maps.files[0]);
	init_curses();
	move(0, 0);
	loop(&maps, old_state);//win, maps);
	endwin();
	for (int i = 0; i < 512; i++)
		free(old_state[i]);
	free(old_state);
	destroy_files(&maps);
	free(path);
}

int main(int ac, char **av)
{
    if (ac > 1) {
	if (av[1][0] == '1') {
	    FAST_RUN = 0;
	}
    }
	start_level();
	return 0;
}
