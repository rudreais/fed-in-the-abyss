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

#define TMP_PATH "/fed-in-the-abyss/maps/1_1"
#define HOME getenv("HOME")
#define PATH strcat((HOME), (TMP_PATH))
#define START_FLOOR '>'

extern const char hard_tiles[];
extern const char transparent_tiles[];

typedef struct {
    int x;
    int y;
} cursor_t;

typedef struct {
    int width;
    int height;
} dim_t;

typedef struct floor {
    int xmax;
    int ymax;
    int xsize;
    int ysize;
    char **design;
} floor_t;

typedef struct {
    WINDOW *win;
    cursor_t *initial_pos;
    dim_t *size;
} tab_t;
