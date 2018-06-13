/*
** RUDREAIS, 06/13/18
** lib/objects
** File description:
** dimensions
*/

#include "libobjects.h"

dim_t *copy_dim(dim_t *src, dim_t *dest)
{
  dest->width = src->width;
  dest->height = src->height;
  return dest;
}

void modify_dim(dim_t *dim, int width, int height)
{
  dim->width = width;
  dim->height = height;
}

dim_t create_dim(int width, int height)
{
  dim_t dim = {.width = width, .height = height};

  return dim;
}
