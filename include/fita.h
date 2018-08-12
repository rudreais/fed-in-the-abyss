/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/include/fita.h
 * Path: /home/rudreais/prog/fed-in-the-abyss/include
 * Created Date: Tuesday, July 10th 2018, 1:34:37 pm
 * Author: rudreais
 *
 * Copyright (c) 2018 rudreais
 */

#pragma once

#include <limits.h>
#include <ncurses.h>
#include "cursor.h"
#include "maps.h"
#include "enemy.h"

/**
 * ...
 */

typedef struct
{
	WINDOW	*win;
	int	level;
} properties_t;

/** Width for the main window */
#define N_COLS		(COLS - 40)

/** Height for the main window */
#define N_LINES		(LINES - 10)

/** Get a good width for the main WINDOW */
#define GET_WIDTH	(((N_COLS % 2) == 0) ? N_COLS - 1 : N_COLS)

/** Get a good height for the main WINDOW */
#define GET_HEIGHT	(((N_LINES % 2) == 0) ? N_LINES - 1 : N_LINES)

/** Get static array size */
#define GET_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

enum direction
{
	/** 0 */
	UP,

	/** 1 */
	RIGHT,

	/** 2 */
	DOWN,

	/** 3 */
	LEFT
};

/**
 * @param path : path to the maps/ directory
 * @return map_t array structure
 *
 * Call generate_maps() and ncurses routine to initialize game.
 */

map_t	**init_level(const char *path);

/**
 * @param map_t : maps array to destroy
 * @param old_state : map array to free
 *
 * Call destroy_maps(), ncurses routine and free(3) to destroy level at process end.
 */

void	destroy_level(map_t **maps, char **old_state);

/**
 * @param prop : pointer to properties of the game
 * @param maps : maps array
 * @param old_state : old state of the current map
 *
 * Basically : game loop. Call game's sub-routine.
 */

void	game_loop(properties_t *prop, map_t **maps, char **old_state);

/**
 * @param player : player structure
 * @param prop : properties_t containing current ncurses window
 * @param maps : maps array
 *
 * Manage the camera during the game, compute player position,
 * center map on the player, and finally print map.
 */

void camera(player_t *player, map_t **maps, properties_t *prop);

/**
 * Soon
 */

cursor_t move_charac(int key, cursor_t *pos, cursor_t *cam, char **map);

/**
 * @param enemy_t array of enemies
 * @param cursor_t pointer to the character being attacked
 * @param enemy_t pointer to the character attacking
 * @param player_t pointer to the player
 *
 * Soon
 */

void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player);

/**
 * @param player_t pointer to player
 *
 * Soon
 */

void screen_charac(player_t *player);

/**
 * Soon
 */

void screen_logs(int who_is, const char *f_name, int atk);

/**
 * @param void
 * @return void
 *
 * Show a death screen when you die.
 */

void screen_death(void);

/**
 * @param char ** current map
 * @param char ** old state of the map
 * @param cursor_t * player's position
 * @param cursor_t * camera's position
 *
 * Soon
 */
void assign_player(char **map, char **old_state, cursor_t *charac, cursor_t *cam);

extern const char *names[];  /** Soon */
extern enemy_t possible_enemies[]; /** Array of all enemy possibilities */
extern int enemies_nb; /** Number of possible_enemies */

extern charac_t base_charac;  /** Soon */
