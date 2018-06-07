/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main header
*/

#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "character.h"

#define TMP_PATH "/fed-in-the-abyss/maps/1_1"

// is used to determine where the character spawns
#define START_FLOOR '>'

// are used to determine the collision
// found in src/map/ as vars.c
extern const char hard_tiles[];
extern const char transparent_tiles[];

/**
 * @param map_t *map
 * @return void
 * @purpose fulfill map pointer with the read file
 * TEMP FUNCTION AS THE MAP WILL BE RANDOMLY GENERATED
 */
void get_map(map_t *map);

/**
 * structure to easier use positions
 */

typedef struct {
    int x;
    int y;
} cursor_t;

/**
 * structure to easier modify dimension of tabs, windows...
 */

typedef struct {
    int width;
    int height;
} dim_t;
