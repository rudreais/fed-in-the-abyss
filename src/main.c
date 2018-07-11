/**
 ** rudreais
 ** main
 **
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "o_strings.h"
#include "cursor.h"
#include "fita.h"
#include "path.h"

void init_curses(void)
{
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
}

int main(void)
{
    printf("%s\n", getpath("maps"));
    return 0;
}
