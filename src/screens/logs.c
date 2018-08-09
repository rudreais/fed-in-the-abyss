/**
 *
 *
 *
 */

#include <string.h>
#include "fita.h"

void screen_death()
{
	char died[] = "You died.";
	char press[] = "press any key to exit";

	clear();
	move(LINES / 2, (COLS / 2) - (strlen(died) / 2));
	printw("You died.\n");
	move((LINES / 2) + 2, (COLS / 2) - (strlen(press) / 2));
	printw("press any key to exit");
	getch();
}

void screen_logs(int who_is, const char *f_name, int atk)
{
	move(N_LINES, 0);
    if (who_is == 1)
	    printw("You hit %s for %d damages\n", f_name, atk);
    else
	    printw("%s hit you for %d damages", f_name, atk);
}
