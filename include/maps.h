#pragma once

#define MAP_SIZE	(512)

#define DEFAULT		"\e[0m"
#define RED		"\e[31;1m"
#define BOLD		"\e[1m"
#define UNDERLINE	"\e[4m"

typedef struct
{
	char	**map;
	char	*name;
} map_t;

/**
 * @param the number of maps you want to generate
 * @return nothing
 * @purpose execute the rust map_generator
 */
void generate_maps(int nb);

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
