/**
 ** rudreais
 ** main
 **
 */

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "fita.h"

int main(int ac, char **av __attribute__((unused)))
{
	map_t **maps;
	char **old_state;

	if (ac > 1) {
		for (int i = 0; i < 7; i++) {
			srand(time(NULL));
			gen_map(i + 1);
			sleep(1);
		}
	}
	maps = init_level("./maps/");
	old_state = my_tabdup(maps[0]->map);
	game_loop(maps, old_state);
	destroy_level(maps, old_state);
	return 0;
}
