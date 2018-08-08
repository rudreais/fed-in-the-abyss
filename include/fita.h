/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/include/fita.h
 * Path: /home/rudreais/prog/fed-in-the-abyss/include
 * Created Date: Tuesday, July 10th 2018, 1:34:37 pm
 * Author: rudreais
 *
 * Copyright (c) 2018 rudreais
 */

#pragma once

#include <ncurses.h>
#include "cursor.h"
#include "maps.h"
#include "enemy.h"

#define N_COLS		(COLS - 40) // the width
#define N_LINES		(LINES - 10) // the height

/**
 * @purpose get a good width for the main WINDOW
 */
#define GET_WIDTH	(((N_COLS % 2) == 0) ? N_COLS - 1 : N_COLS)

/**
 * @purpose get a good height for the main WINDOW
 */
#define GET_HEIGHT	(((N_LINES % 2) == 0) ? N_LINES - 1 : N_LINES)

#define GET_ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

map_t	**init_level(const char *path);
void	destroy_level(map_t **maps, char **old_state);

void	game_loop(map_t **maps, char **old_state);
int	border_cam(cursor_t *cam);

cursor_t move_charac(int key, cursor_t *pos, cursor_t *cam, char **map);
void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player);

/*****************************/
/* src/screens/player_info.c */
/*****************************/
/**
 * @param
 * @return
 * @purpose
 */
void screen_charac(player_t *player);

/**
 *
 *
 *
 */
void screen_logs(void);

void screen_death(void);

/****************/
/* src/prints.c */
/****************/
/**
 * @param the current WINDOW, the char to print
 * @return nothing
 * @purpose print pretty characters using attributes from ncurses
 */
void print_charac(WINDOW *win, cursor_t *pos);

/**
 * @param the current WINDOW, the camera position, the map to print
 * @return nothing
 * @purpose print the map and refresh the screen
 */
void centered_map(WINDOW *win, cursor_t *cam, map_t **maps);

/****************/
/* src/player.c */
/****************/
/**
 * @param double char ptr x2, cursor ptr x2
 * @return nothing
 * @purpose assign player to map and backup map's state
 */
void assign_player(char **map, char **old_state, cursor_t *charac, cursor_t *cam);

/***************/
/* src/main.c */
/***************/
void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player);


void screen_charac(player_t *player);
void screen_death();
void screen_logs();

extern enemy_t possible_enemies[];
extern int enemies_nb;
