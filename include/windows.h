/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#include <ncurses.h>
#include "character.h"

#pragma once

typedef struct {
    int width;
    int height;
} dim_t;

typedef struct {
    WINDOW *win;
    cursor_t *initial_pos;
    dim_t *size;
} tab_t;

WINDOW *create_window(cursor_t *pos, dim_t *size);
