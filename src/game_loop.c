#include <ncurses.h>
#include <stdlib.h>
#include "fita.h"

void game_loop(map_t **maps, char **old_state)
{
	WINDOW *win = newwin(GET_HEIGHT, GET_WIDTH, 0, 0);
	player_t player;
	enemy_t *enemies[10];
	int c = 0; // key pressed
	cursor_t enemy_pos;

	create_player(&player);
	add_enemy(enemies);
	while (c != 'q') {
		enemy_pos = move_charac(c, &player.pos, &player.pos_bak, maps[0]->map);
		assign_player(maps[0]->map, old_state, &player.pos, &player.pos_bak);
		player.pos_bak = player.pos;
		enemy_turn(&player, enemies[0], maps[0]->map, enemies, old_state);
		if (player.charac.hp <= 0) {
			screen_death();
			return;
		}
		assign_enemy(maps[0]->map, old_state, enemies[0]);
		// if an enemy is killed, the player disappear
		assign_player(maps[0]->map, old_state, &player.pos, &player.pos_bak);
		if (enemy_pos.x != -1 && enemy_pos.y != -1)
			attack(enemies, &enemy_pos, &player, &player);
		camera(&player, win, maps);
		wmove(win, 1, 1); // test purpose
		wprintw(win, "%d", enemies[0]->charac.hp);
		wprintw(win, "\t%d\t%d", enemy_pos.x, enemy_pos.y);
		screen_charac(&player);
		screen_logs();
		refresh();
		wrefresh(win);
		c = getch();
	}
	delwin(win);
}
