/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "windows.h"

void game_loop()
{
	int c;

	while (c != 'q') {
		c = getch();
	}
}

int main(void)
{
	dungeon_t abyss;
	tab_t **tabs = calloc(1, sizeof(tab_t *));

	init_dungeon(&abyss);
	init_tabs(tabs);
	init_curse();
	game_loop();
	endwin();
}