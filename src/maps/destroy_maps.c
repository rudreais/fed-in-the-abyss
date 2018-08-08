#include <stdlib.h>
#include "maps.h"

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
