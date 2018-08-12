/**
 *
 *
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "maps.h"
#include "my.h"

static void exec_binary(char **av)
{
	switch (fork()) {
	case -1:
		perror("Fork(): ");
		exit(EXIT_FAILURE);
	case 0:
		execv(av[0], av);
		// fall through
	default:
		wait(NULL);
	}
}

void generate_maps(int nb)
{
	char *av[5] = {
		"./map_generator",
		NULL,
		NULL,
		my_snprintf("%d", MAP_SIZE),
		NULL
	};

	printf("%sGenerating maps...%s\n", RED, DEFAULT);
	chdir("./maps/");
	for (int i = 0; i < nb; i++) {
		srand(time(NULL));
		av[1] = my_snprintf("%d_1", i + 1);
		av[2] = my_snprintf("%d", (rand() + 1) % 999);
		exec_binary(av);
		free(av[1]);
		free(av[2]);
		sleep(1);
	}
	free(av[3]);
	chdir("..");
}
