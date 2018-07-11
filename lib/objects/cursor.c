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

void cursor_modify(Cursor *self, int newx, int newy)
{
    self->x = newx;
    self->y = newy;
}

void CursorInit(Cursor *self, int x, int y)
{
    self->x = x;
    self->y = y;
    self->modify = cursor_modify;
}