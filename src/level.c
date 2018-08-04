#include <stdlib.h>
#include "fita.h"

map_t **init_level(const char *path)
{
	map_t **maps = init_maps(path);

	if (!maps)
		return NULL;
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	move(0, 0);
	return maps;
}

void destroy_level(map_t **maps, char **old_state)
{
	endwin();
	for (int i = 0; old_state[i] != NULL; i++)
		free(old_state[i]);
	free(old_state);
	destroy_maps(maps);
}
