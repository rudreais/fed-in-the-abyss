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

/** width for the main window */
#define N_COLS		(COLS - 40)

typedef struct {
		WINDOW *win;
		int level;
} properties_t;

/** height for the main window */
#define N_LINES		(LINES - 10)

/** get a good width for the main WINDOW */
#define GET_WIDTH	(((N_COLS % 2) == 0) ? N_COLS - 1 : N_COLS)

/** get a good height for the main WINDOW */
#define GET_HEIGHT	(((N_LINES % 2) == 0) ? N_LINES - 1 : N_LINES)

/** get array size */
#define GET_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

enum direction
{
 /** 1 */
 UP = 1,
 /** 2 */
 RIGHT,
 /** 3 */
 DOWN,
 /** 4 */
 LEFT
};

/**
 * @param const char * path to the maps
 * @return map_t ** map_t allocated structure
 */
map_t	**init_level(const char *path);

/**
 * @param map_t ** map_t pointer to destroy
 * @param char ** old state to free
 * @return void
 */
void	destroy_level(map_t **maps, char **old_state);

void	game_loop(properties_t *prop, map_t **maps, char **old_state);
enum direction	border_cam(cursor_t *cam);
void camera(player_t *player, WINDOW *win, map_t **map);

cursor_t move_charac(int key, cursor_t *pos, cursor_t *cam, char **map);

/**
 * @param enemy_t array of enemies
 * @param cursor_t pointer to the character being attacked
 * @param enemy_t pointer to the character attacking
 * @param player_t pointer to the player
 * @return void
 */
void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player);

/**
 * @param player_t pointer to player
 * @return void
 */
void screen_charac(player_t *player);

/**
 * @param void
 * @return void
 */
void screen_logs(int who_is, const char *f_name, int atk);

/**
 * @param void
 * @return void
 */
void screen_death(void);

/**
 * @param WINDOW *
 * @param char character to print
 * @return nothing
 */
void print_charac(WINDOW *win, cursor_t *pos);

/**
 * @param WINDOW *
 * @param cursor_t the camera position
 * @param map_t the map to print
 * @return nothing
 */
void centered_map(WINDOW *win, cursor_t *cam, map_t **maps);

/**
 * @param char ** current map
 * @param char ** old state of the map
 * @param cursor_t * player's position
 * @param cursor_t * camera's position
 * @return nothing
 */
void assign_player(char **map, char **old_state, cursor_t *charac, cursor_t *cam);

extern const char *names[];
extern enemy_t possible_enemies[];
extern int enemies_nb;
