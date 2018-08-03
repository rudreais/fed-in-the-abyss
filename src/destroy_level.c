#include <stdlib.h>
#include "fita.h"

void destroy_maps(map_t **maps)
{
	for (int i = 0; maps[i] != NULL; i++) {
		for (int j = 0; maps[i]->map[j] != NULL; j++)
			free(maps[i]->map[j]);
		free(maps[i]->map);
		free(maps[i]->name);
		free(maps[i]);
	}
	free(maps);
}

void destroy_level(map_t **maps, char **old_state)
{
	endwin();
	for (int i = 0; old_state[i] != NULL; i++)
		free(old_state[i]);
	free(old_state);
	destroy_maps(maps);
}
