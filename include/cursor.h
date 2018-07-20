/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/include/cursor.h
 * Path: /home/rudreais/prog/fed-in-the-abyss/include
 * Created Date: Tuesday, July 10th 2018, 1:17:40 pm
 * Author: rudreais
 *
 * Copyright (c) 2018 Your Company
 */

#pragma once

typedef struct cursor_s cursor_t;

struct cursor_s {
    int x;
    int y;
};

void cursor_modify(cursor_t *self, int newx, int newy);

void cursor_copy(cursor_t *dest, cursor_t *src);
