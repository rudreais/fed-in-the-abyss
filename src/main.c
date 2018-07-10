/**
 ** rudreais
 ** main
 **
 */

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "o_string.h"
#include "o_strings.h"
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
  String s1, s2;
  Strings arr_s;

  s1.StringInit = StringInit;
  s2.StringInit = StringInit;
  s1.StringInit(&s1, "test value 1");
  s2.StringInit(&s2, "test value 2");
  printf("%s\n%s\n", s1.s, s2.s);

  arr_s.StringsInit = StringsInit;
  arr_s.StringsInit(&arr_s);
  arr_s.push_back(&arr_s, &s1);
  arr_s.push_back(&arr_s, &s2);
  printf("%s\n%s\n", arr_s.array[0]->s, arr_s.array[1]->s);
  
  return 0;
}
