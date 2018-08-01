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

    move(LINES / 2, (COLS / 2) - (strlen(died) / 2));
    printw("You died.\n");
    move((LINES / 2) + 2, (COLS / 2) - (strlen(press) / 2));
    printw("press any key to exit");
    getch();
}

void screen_logs()
{
    move(N_LINES, 0);
    printw("HERE IS LOGS\n");
    printw("ON THE REST OF THE LINES");
}
