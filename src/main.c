/**
 ** rudreais
 ** main
 **
 */

#include <unistd.h>
#include "fita.h"

int main(int ac, char **av __attribute__((unused)))
{
	files_t maps;
	char **old_state = NULL;

	if (ac > 1) {
		for (int i = 0; i < 7; i++) {
			gen_map(i + 1);
			sleep(1);
		}
	}
	init_level(&maps, &old_state);
	game_loop(&maps, old_state);//win, maps);
	destroy_level(&maps, old_state);
	return 0;
}
