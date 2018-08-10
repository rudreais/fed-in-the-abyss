/**
 *
 *
 *
 */

#include <stdlib.h>
#include "fita.h"

const charac_t possible_charac[] = {
  //level, hp, hp_max, mp, str, def, xp
   {1, 10, 10, 4, 3, 1, 0}, // R
   {1, 14, 14, 2, 5, 0, 0}, // W
   {1,  8, 8,  5, 1, 3, 0}, // Z
   {1, 10, 10, 3, 2, 2, 0}, // O
};

const char *names[] = {
		       "ROGUE",
		       "WARRIOR",
		       "MONSTER",
		       "OGRE"
};

enemy_t possible_enemies[] = {
	// {char name, pos, pos_bak, charac}
			      {'R', NULL, {0}, {0}, possible_charac[0]},
	{'W', NULL, {0}, {0}, possible_charac[1]},
	{'M', NULL, {0}, {0}, possible_charac[2]},
	{'O', NULL, {0}, {0}, possible_charac[3]}
};

int enemies_nb = GET_ARRAY_SIZE(possible_enemies);

void enemy_turn(player_t *player, enemy_t *enemy, char **map, enemy_t **enemies, char **state)
{
	int e_key = -1;
	cursor_t player_pos;

	if (enemy->charac.hp <= 0) {
		enemy->name = state[enemy->pos_bak.y][enemy->pos_bak.x];
		assign_enemy(map, state, enemy);
		return;
	}
	if (enemy->pos.x > player->pos.x)
		e_key = KEY_LEFT;
	else if (enemy->pos.y > player->pos.y)
		e_key = KEY_UP;
	else if (enemy->pos.x < player->pos.x)
		e_key = KEY_RIGHT;
	else if (enemy->pos.y < player->pos.y)
		e_key = KEY_DOWN;
	player_pos = move_charac(e_key, &enemy->pos, &enemy->pos_bak, map);
	if (player_pos.x > -1 && player_pos.y > -1)
		attack(enemies, &player_pos, enemy, player);
}

void assign_enemy(char **map, char **old_state, enemy_t *enemy)
{
	map[enemy->pos_bak.y][enemy->pos_bak.x] = old_state[enemy->pos_bak.y][enemy->pos_bak.x];
	map[enemy->pos.y][enemy->pos.x] = enemy->name;
	enemy->pos_bak = enemy->pos;
}

void add_enemy(enemy_t **enemies, int level)
{
	int index = 0;
	enemy_t *enemy = malloc(sizeof(enemy_t));

	index = rand() % 4;
	*enemy = (enemy_t) {
		.name = possible_enemies[index].name,
		.f_name = names[index],
		.charac = possible_enemies[index].charac,
		.charac.level = level,
		.pos = {
			.x = 50,
			.y = 20
		},
		.pos_bak = {
			.x = 50,
			.y = 20
		}
	};
	enemies[0] = enemy;
	enemies[1] = NULL;
}
