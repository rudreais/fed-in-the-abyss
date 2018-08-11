#pragma once

/** MAP_SIZE is the map size : it's a square */
#define MAP_SIZE	(512)

/** Default shell color */
#define DEFAULT		"\e[0m"

/** Red shell color */
#define RED		"\e[31;1m"

/** Bold shell font */
#define BOLD		"\e[1m"

/** Underline shell font */
#define UNDERLINE	"\e[4m"

/**
 * map_t stores all the data linked to a map.
 */

typedef struct
{
	char **map;
	char *name;
} map_t;

/**
 * @param nb : number of maps you want to generate
 *
 * Execute the rust map_generator in maps/ directory within a loop,
 * call sleep(3) and srand(3) to randomize seed of each map.
 */

void generate_maps(int nb);

/**
 * @param path : path to the directory where map_generator is stored
 * @return maps_t array, or NULL if no map are found
 *
 * Call opendir(3) read map files in path directory.
 * Initialize maps_t structure.
 */

map_t **init_maps(const char *path);

/**
 * @param maps : maps array
 *
 * Destroy maps array by calling free(3).
 */

void destroy_maps(map_t **maps);
