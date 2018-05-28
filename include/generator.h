/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** map generator header
*/

#include <stdlib.h>

#pragma once

const char hard_tiles[] = {
    '#',
    '\0',
};

const char transparent_tiles[] = {
    '.',
    '\0',
};

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
