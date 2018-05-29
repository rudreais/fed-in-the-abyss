/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#pragma once

#include <ncurses.h>
#include "board.h"

cursor_t get_start(floor_t *f_floor);
void get_map(floor_t *f_floor);
void init_tab(tab_t *tab, cursor_t *pos, dim_t *size);

void init_curse(void);