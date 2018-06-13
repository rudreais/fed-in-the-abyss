/*
** RUDREAIS, 06/13/18
** lib/objects
** File description:
** header
*/

#pragma once


/**********************\
*                      *
*     cursors.c        *
*                      *
\**********************/

/*
 * structure to make easier use of axis
 */
typedef struct {
  int x;
  int y;
} cursor_t;

/**
 * @param cursor_t pointer, int x, int y
 * @return void
 * @purpose modify pointer with given value
 */
void modify_cursor(cursor_t *cursor, int x, int y);

/**
 * @param int x, int y
 * @return cursor_t newly created
 * @purpose create cursor
 */
cursor_t create_cursor(int x, int y);


/**********************\
*                      *
*     dimensions.c     *
*                      *
\**********************/

typedef struct {
  int width;
  int height;
} dim_t;

/**
 * @param dim_t pointer, int width, int height
 * @return void
 * @purpose modify pointer with given value
 */
void modify_dim(dim_t *dim, int width, int height);

/**
 * @param int width, int height
 * @return dim_t newly created
 * @purpose create dimension
 */
dim_t create_dim(int width, int height);

