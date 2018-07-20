/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/src/cursor.c
 * Path: /home/rudreais/prog/fed-in-the-abyss/src
 * Created Date: Tuesday, July 10th 2018, 1:17:36 pm
 * Author: rudreais
 *
 * Copyright (c) 2018 Your Company
 */

#include <stdlib.h>
#include "cursor.h"

void cursor_modify(cursor_t *self, int newx, int newy)
{
    self->x = newx;
    self->y = newy;
}

void cursor_copy(cursor_t *dest, cursor_t *src)
{
	dest->x = src->x;
	dest->y = src->y;
}
