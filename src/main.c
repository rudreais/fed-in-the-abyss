/**
 ** rudreais
 ** main
 **
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ncurses.h>
#include "libobjects.h"
#include "tmp.h"

void init_curses(void)
{
  initscr();
  raw();
  keypad(stdscr, TRUE);
  noecho();
}

int main(void)
{
  map_t map = create_map();

  for (int i = 0; i < map.ymax; i++)
    printf("%s\n", map.design[i]);
  return 0;
}
