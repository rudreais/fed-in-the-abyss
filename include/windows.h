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
 * using macro "PATH" from board.h
 * reading map from path and fulfilling array
 */
void get_map(floor_t *f_floor);

/**
 * starts ncurses mode for the terminal
 * note: if any problem occurs before the endwin() call, the terminal will be stuck
 * in non-cannonical mode
 */
void init_curse(void);
