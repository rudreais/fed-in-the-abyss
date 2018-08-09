/*
 * src/game_loop.c
 *
 * main game loop
 */

#include <ncurses.h>
#include <stdlib.h>
#include "fita.h"

static void call_print(player_t *player, cursor_t *fixed, map_t **maps, properties_t *prop)
{
	int border = 0; // define if fixed cam pos is used or not

	if ((border = border_cam(&player->pos)) > 0) {
		if (border == 2 || border == 4) // border on left/right
			fixed->y = player->pos.y;
		if (border == 1 || border == 3) // border on top/bottom
			fixed->x = player->pos.x;
		centered_map(prop->win, fixed, maps);
		refresh();
		wrefresh(prop->win);
	} else {
		fixed = &player->pos_bak;
		centered_map(prop->win, &player->pos, maps);
	}
}

void parse_key(int key)
{

}

void game_loop(properties_t *prop, map_t **maps, char **old_state)
{
	cursor_t fixed;
	player_t player;
	enemy_t *enemies[10];
	int c = 0; // key pressed
	cursor_t enemy_pos;
	int turn = 0;

	create_player(&player);
	fixed = player.pos;
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
		call_print(&player, &fixed, maps, prop);
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
