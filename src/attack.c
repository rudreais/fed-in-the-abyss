/*
 * src/attack.c
 *
 * attack functions and algo's file
 */

#include <math.h>
#include "fita.h"

static void attr_exp(player_t *player)
{
	int level = player->charac.level;

	player->charac.level = cbrt(player->charac.xp / 1.25);
	level = player->charac.level;
	player->charac.hp_max = base_charac.hp_max + (2 * level);
	player->charac.mp = base_charac.mp + (1 * level);
	player->charac.str = base_charac.str + (2 * level);
	player->charac.def = base_charac.def + (2 * level);
}

void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player)
{
	cursor_t backup = {.x = defender->x, .y = defender->y };
	int hit_for;

	if (turn->name != '@') {
		hit_for = player->charac.hp - turn->charac.str;
		player->charac.hp = hit_for;
		player->charac.xp = 34;
		screen_logs(1, turn->f_name, hit_for);
		attr_exp(player);
		return;
	}
	for (int i = 0; enemies[i]; i++) {
		if (enemies[i]->pos.x == backup.x && enemies[i]->pos.y == backup.y) {
			hit_for = enemies[i]->charac.hp - turn->charac.str;
			enemies[i]->charac.hp = hit_for;
			screen_logs(0, enemies[i]->f_name, hit_for);
		}
	}
}
