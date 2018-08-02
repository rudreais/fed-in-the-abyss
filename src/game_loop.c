#include <ncurses.h>
#include <stdlib.h>
#include "fita.h"

void game_loop(files_t *maps, char **old_state)
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