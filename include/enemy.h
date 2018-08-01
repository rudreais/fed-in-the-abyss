#pragma once

#include "fita.h"

typedef struct enemy_s enemy_t;
typedef struct charac_s charac_t;

typedef enemy_t player_t;

/*
 * I'm not sure it's a good practice to differentiate 2 variables of the same
 * type, by creating a type "copy". I think differents variables names are enough.
 * I keep it while waiting for an explanation/justification/details from you
 */

struct charac_s {
    int level;
    int hp;
    int mp;
    int str;
    int def;
};

struct enemy_s {
    char name;
    cursor_t pos;
    cursor_t pos_bak;
    charac_t charac;
};

/****************/
/* src/player.c */
/****************/
/**
 * @param ptr to player_t
 * @return void
 * @purpose create player (assigning pointers as charac and pos)
 */
void create_player(player_t *player);

/****************/
/* src/enemy.c */
/****************/
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
void add_enemy(enemy_t **enemies);
