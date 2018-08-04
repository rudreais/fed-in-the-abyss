#pragma once

typedef struct
{
	char	**map;
	char	*name;
} map_t;

/**
 * @param path to the directory to init
 * @return maps array
 * @purpose read maps in path, initialize maps
 */
map_t **init_maps(const char *path);

/**
 * @param maps array
 * @return nothing
 * @purpose destroy each map
 */
void destroy_maps(map_t **maps);
