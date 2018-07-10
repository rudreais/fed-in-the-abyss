/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/include/cursor.h
 * Path: /home/rudreais/prog/fed-in-the-abyss/include
 * Created Date: Tuesday, July 10th 2018, 1:17:40 pm
 * Author: rudreais
 * 
 * Copyright (c) 2018 Your Company
 */

#pragma once

typedef struct cursor_s Cursor;

struct cursor_s {
    int x;
    int y;
    void(*init)(Cursor *, int, int);
    void(*destroy)(Cursor *);
    void(*modify)(Cursor*, int, int);
};

void CursorInit(Cursor *self, int x, int y);
void CursorDestroy(Cursor *self);

void cursor_modify(Cursor *self, int newx, int newy);
