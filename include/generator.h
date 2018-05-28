/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** map generator header
*/

#include <stdlib.h>

#pragma once

#define START_FLOOR '>'

extern const char *path;
extern const char hard_tiles[];
extern const char transparent_tiles[];

typedef struct floor {
    int xmax;
    int ymax;
    int xsize;
    int ysize;
    char **design;
} floor_t;

enum {
    tileUnused = 0,
    tileDirtWall,
    tileDirtFloor,
    tileStoneWall,
    tileCorridor,
    tileDoor,
    tileUpStairs,
    tileDownStairs,
    tileChest
};

// src/map/generator
// main.c
void map_generator(void);
int main_map_gen(void);

//src/map/
// prints.c
void print_map(floor_t *f_floor, cursor_t *pos);
