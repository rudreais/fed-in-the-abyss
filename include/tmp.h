/*
** RUDREAIS, 06/13/18
** tmp
** File description:
** header
*/

#pragma once

#include <ncurses.h>

char *read_line(int fd);

/**********************\
*                      *
*       init.c         *
*                      *
\**********************/

/**
 * @param void
 * @return void
 * @purpose initialize non canonical terminal for ncurses
 */
void init_curses(void);
