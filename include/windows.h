/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#pragma once

#include <ncurses.h>
#include "board.h"

/**
 * using macro "START_FLOOR" from board.h
 * getting the first occuring value at given coordonates and returns it
 */
cursor_t *get_start(floor_t *f_floor);

/**
 * using macro "PATH" from board.h
 * reading map from path and fulfilling array
 */
void get_map(floor_t *f_floor);

/**
 * initializing's functions
 */
void init_dungeon(dungeon_t *dungeon);
void init_tabs(tab_t **tabs);

/**
 * starts ncurses mode for the terminal
 * note: if any problem occurs before the endwin() call, the terminal will be stuck
 * in non-cannonical mode
 */
void init_curse(void);

/**
 * prints the game
 */
void print_game(dungeon_t *abyss, tab_t **tabs);