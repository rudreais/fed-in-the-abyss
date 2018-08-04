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
