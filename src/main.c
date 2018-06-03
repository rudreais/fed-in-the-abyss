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

char *my_strdup(char *str);

void add_chars(floor_t *f_floor)
{
	character_t my_char;
	char *name = "player";
	char appear = '@';

	my_char.name = my_strdup(name);
	my_char.appear = appear;
	f_floor->chars = malloc(sizeof(character_t *) * 1);
	my_char.pos = get_start(f_floor);
	f_floor->chars[0] = &my_char;
}

void game_loop(dungeon_t *abyss, tab_t **tabs, int index)
{
	cursor_t map_pos = {.x = 10, .y = 5};
	map_t map;
	int c;

	get_map(abyss->floors[index]);
	add_chars(abyss->floors[index]);
	while (c != 'q') {
		print_game(abyss, tabs);
		c = getch();
	}
}

int main(void)
{
	dungeon_t abyss;
	tab_t **tabs = calloc(1, sizeof(tab_t *));

	init_curse();
	init_dungeon(&abyss);
	init_tabs(tabs);
	tabs[0]->tab_pos->x = 20;
	tabs[0]->tab_pos->y = 2;
	tabs[0]->tab_size->height = 26;
	tabs[0]->tab_size->width = 50;
	tabs[0]->win = newwin(tabs[0]->tab_size->height, tabs[0]->tab_size->width,
							tabs[0]->tab_pos->y, tabs[0]->tab_pos->x);
	for (int i = 0; i < 1; i++) {
		game_loop(&abyss, tabs, i);
	}
	endwin();
}