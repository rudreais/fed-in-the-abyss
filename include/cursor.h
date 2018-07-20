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

/****************/
/* src/cursor.c */
/****************/
/**
 * @param takes the current cursor, and the new position as 2 int
 * @return nothing
 * @purpose modify a cursor
 */
void cursor_modify(cursor_t *self, int newx, int newy);

/**
 * @param the destination cursor and the source cursor
 * @return nothing
 * @purpose copy a cursor
 */
void cursor_copy(cursor_t *dest, cursor_t *src);
