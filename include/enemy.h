#pragma once

#include "fita.h"

typedef struct enemy_s enemy_t;
typedef struct charac_s charac_t;

#define player_t enemy_t // use player_t instead of enemy_t for player

struct charac_s {
    int level;
    int hp;
    int mp;
    int str;
    int def;
};

struct enemy_s {
    char name;
    cursor_t *pos;
    cursor_t *pos_bak;
    charac_t *charac;
};

/****************/
/* src/player.c */
/****************/
/**
 * @param nothing
 * @return player ptr newly allocated
 * @purpose create player (assigning pointers as charac and pos)
 */
player_t *create_player(void);

/****************/
/* src/enemy.c */
/****************/
/**
 * @param cursor ptr, enemy_t ptr, double char ptr
 * @return nothing
 * @purpose play the enemy turn
 */
void enemy_turn(cursor_t *player, enemy_t *enemy, char **map);

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
void add_enemy(enemy_t **enemies);
