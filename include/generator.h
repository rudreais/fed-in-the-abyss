/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** map generator header
*/

#pragma once

#include "board.h"

// src/map/generator
// main.c
void map_generator(void);
int main_map_gen(void);

//src/map/
// prints.c
void print_map(floor_t *f_floor, cursor_t *pos);
void print_window(tab_t *tab, cursor_t *pos);
void print_map_window(tab_t *tab, floor_t *f_floor, cursor_t *pos);
