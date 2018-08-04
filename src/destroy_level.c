#include <stdlib.h>
#include "fita.h"

void destroy_level(map_t **maps, char **old_state)
{
	endwin();
	for (int i = 0; old_state[i] != NULL; i++)
		free(old_state[i]);
	free(old_state);
	destroy_maps(maps);
}
