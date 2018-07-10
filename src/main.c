/**
 ** rudreais
 ** main
 **
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "o_string.h"
#include "cursor.h"
#include "fita.h"

void init_curses(void)
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
}

int main(void)
{
  return 0;
}
