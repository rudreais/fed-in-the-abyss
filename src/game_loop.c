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
	int key = 0;
	cursor_t enemy_pos;
	int turn = 0;

	create_player(&prop->player);
	add_enemy(prop->enemies, prop->level);
	while (key != 'q') {
		enemy_pos = move_charac(key, &prop->player.pos, &prop->player.pos_bak, maps[0]->map);
		assign_player(maps[0]->map, old_state, &prop->player.pos, &prop->player.pos_bak);
		prop->player.pos_bak = prop->player.pos;
		enemy_turn(&prop->player, prop->enemies[0], maps[0]->map, prop->enemies, old_state);
		if (prop->player.charac.hp <= 0) {
			screen_death();
			return;
		}
		assign_enemy(maps[0]->map, old_state, prop->enemies[0]);
		// if an enemy is killed, the player disappear
		// to prevent, re-assign player to map
		assign_player(maps[0]->map, old_state, &prop->player.pos, &prop->player.pos_bak);
		if (enemy_pos.x != -1 && enemy_pos.y != -1) {
			attack(prop->enemies, &enemy_pos, &prop->player, &prop->player);
		}
		camera(&prop->player, maps, prop);
		screen_charac(&prop->player);
		parse_key(key);
		if ((turn % 10) == 0) {
			if (prop->player.charac.hp < prop->player.charac.hp_max)
				prop->player.charac.hp++;
		}
		refresh();
		wrefresh(prop->win);
		key = getch();
		turn++;
	}
	delwin(prop->win);
}
