#include <ncurses.h>
#include <stdlib.h>
#include "fita.h"

void destroy_level(files_t *maps, char **old_state)
{
	endwin();
	for (int i = 0; i < 512; i++)
		free(old_state[i]);
	free(old_state);
	destroy_files(maps);
}
