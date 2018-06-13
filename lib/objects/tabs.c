/*
** RUDREAIS, 06/13/18
** lib/objects
** File description:
** tabs
*/

#include "libobjects.h"

void modify_tab(tab_t *tab, cursor_t *pos, dim_t *dim)
{
  tab->pos = pos;
  tab->dim = dim;
}

tab_t create_tab(cursor_t *pos, dim_t *dim)
{
  tab_t tab = {.pos = pos, .dim = dim};

  return tab;
}
