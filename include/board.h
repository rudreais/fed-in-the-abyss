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
extern const char hard_tiles[];
extern const char transparent_tiles[];

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

typedef struct {
    int str;
    int intel;
    int wis;
    int dex;
    int con;
    int chr;
} stats_t;

typedef struct {
    char *name;
    char appear;
    stats_t characteristics;
    cursor_t *pos;
} character_t;

/**
 * the terminal is a block composed of "bricks" also called tabs
 * each tabs has its own WINDOW (ncurses), size, and position.
 * for example the main window (where the map is) is a tab
 */

typedef struct {
    WINDOW *win;    
    cursor_t *tab_pos;
    dim_t *tab_size;
} tab_t;

typedef struct {
    char **map;
	int ymax;
    tab_t *parent_tab;
    cursor_t *pos;
} map_t;

/**
 * each floor of the dungeon will has a certain design randomly generated
 * the structure contains the number of line the map contains (reading purpose)
 */

typedef struct {
    int ymax;
    char **design;
    character_t **chars;
} floor_t;

/**
 * structure that contains every floors, character, etc
 */

typedef struct {
    floor_t **floors;
} dungeon_t;
