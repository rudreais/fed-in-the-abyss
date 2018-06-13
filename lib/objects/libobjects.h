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
 * @param cursor_t pointer src, cursor_t pointer dest
 * @return cursor_t
 * @purpose copy src into dest
 */
cursor_t *copy_cursor(cursor_t *src, cursor_t *dest);

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
 * @param cursor_t pointer src, cursor_t pointer dest
 * @return cursor_t
 * @purpose copy src into dest
 */
dim_t *copy_dim(dim_t *src, dim_t *dest);

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

/**********************\
*                      *
*        tabs.c        *
*                      *
\**********************/

typedef struct {
  cursor_t *pos;
  dim_t *dim;
} tab_t;

/**
 * @param tab_t pointer, cursor_t pointer, dim_t pointer
 * @return void
 * @purpose modify tab pointer with given value
 */
void modify_tab(tab_t *tab, cursor_t *pos, dim_t *dim);

/**
 * @param cursor_t pointer, dim_t pointer
 * @return tab_t newly created
 * @purpose create tab
 */
tab_t create_tab(cursor_t *pos, dim_t *dim);

/**********************\
 *                      *
 *        tabs.c        *
 *                      *
\**********************/

typedef struct {
  char **design;
  int ymax;
} map_t;

map_t create_map(void);
