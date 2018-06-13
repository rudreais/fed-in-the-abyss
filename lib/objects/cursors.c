/*
** RUDREAIS, 06/13/18
** lib/objects
** File description:
** cursor
*/

#include "libobjects.h"

cursor_t *copy_cursor(cursor_t *src, cursor_t *dest)
{
  dest->x = src->x;
  dest->y = src->y;
  return dest;
}

void modify_cursor(cursor_t *cursor, int x, int y)
{
  cursor->x = x;
  cursor->y = y;
}

cursor_t create_cursor(int x, int y)
{
  cursor_t cursor = {.x = x, .y = y};

  return cursor;
}
