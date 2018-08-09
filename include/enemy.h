#pragma once

typedef struct
{
		int level;
		int hp;
		int hp_max;
		int mp;
		int str;
		int def;
		int xp;
} charac_t;

typedef struct
{
	char name;
	const char *f_name;
	cursor_t pos;
	cursor_t pos_bak;
	charac_t charac;
} enemy_t;

typedef enemy_t player_t;

/**
 * @param ptr to player_t
 * @return void
 * @purpose create player (assigning pointers as charac and pos)
 */
void create_player(player_t *player);

/**
 * @param cursor ptr, enemy_t ptr, double char ptr
 * @return nothing
 * @purpose play the enemy turn
 */
void enemy_turn(enemy_t *player, enemy_t *enemy, char **map, enemy_t **enemies, char **state);

/**
 *
 *
 *
 */
void assign_enemy(char **map, char **old_state, enemy_t *enemy);

/**
 *
 *
 *
 */
void add_enemy(enemy_t **enemies, int level);
