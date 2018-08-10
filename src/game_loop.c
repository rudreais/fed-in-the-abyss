/*
 * src/game_loop.c
 *
 * main game loop
 */

#include <ncurses.h>
#include <stdlib.h>
#include "fita.h"

void parse_key(int key)
{
	switch (key) {
	case 'i':
		printw("inventory");
		break;
	case 's':
		printw("spells");
		break;
	default:
		break;
	}
}

void game_loop(properties_t *prop, map_t **maps, char **old_state)
{
	player_t player;
	enemy_t *enemies[10];
	int c = 0; // key pressed
	cursor_t enemy_pos;
	int turn = 0;

	create_player(&player);
	add_enemy(enemies, prop->level);
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
		if (enemy_pos.x != -1 && enemy_pos.y != -1) {
			attack(enemies, &enemy_pos, &player, &player);
		}
		camera(&player, maps, prop);
		screen_charac(&player);
		parse_key(c);
		if ((turn % 10) == 0) {
			if (player.charac.hp < player.charac.hp_max)
				player.charac.hp++;
		}
		refresh();
		wrefresh(prop->win);
		c = getch();
		turn++;
	}
	delwin(prop->win);
}
