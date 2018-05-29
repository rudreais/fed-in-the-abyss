/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** main
*/

#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"
#include "windows.h"
#include "generator.h"

void game_loop()
{
	int c;

	while (c != 'q') {
		c = getch();
	}
}

void init_dungeon(dungeon_t *dungeon)
{
	
}

int main(void)
{
	dungeon_t abyss;

	abyss.floors = calloc(1, sizeof(floor_t *) * 1);
	init_dungeon(&abyss);
	init_curse();
	game_loop();
	endwin();
}