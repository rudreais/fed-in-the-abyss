/**
 ** rudreais
 ** main
 **
 */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include "fita.h"
#include "my.h"

const char *m = "Usage:\n\t./fita\nOption:\n\t%s--generate-maps %s%snumber\n%s";

int usage(char *error)
{
		if (error)
				printf("%s%s%s\n", RED, error, DEFAULT);
		printf(m, BOLD, DEFAULT, UNDERLINE, DEFAULT);
		return 1;
}

int main(int ac, char **av)
{
		map_t **maps;
		char **old_state;
		properties_t *prop = malloc(sizeof(properties_t));

		if (ac > 2) {
				if (!strcmp(av[1], "--generate-maps"))
						generate_maps(atoi(av[2]));
				else
						return usage(NULL);
		}
		maps = init_level("./maps/");
		prop->win = newwin(GET_HEIGHT, GET_WIDTH, 0, 0);
		prop->level = 0;
		if (!maps)
				return usage("Maps not found in maps/");
		old_state = my_tabdup(maps[0]->map);
		game_loop(prop, maps, old_state);
		destroy_level(maps, old_state);
		return 0;
}
