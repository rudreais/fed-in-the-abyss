/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#pragma once

#include "board.h"

typedef struct {
    int str;
    int intel;
    int wis;
    int dex;
    int con;
    int chr;
} stats_t;

typedef struct {
    stats_t characteristics;
    cursor_t *pos;
} character_t;