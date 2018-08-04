/**
 *
 *
 *
 */

#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "fita.h"

extern char **environ;

void gen_map(int level)
{
	char *av[5] = {
		MAP_GENERATOR,
		my_snprintf("%d_1", level),
		my_snprintf("%d", (rand() + 1) % 999),
		my_snprintf("%d", MAP_SIZE),
		NULL
	};

	switch (fork()) {
	case -1: {
		perror("Fork(): ");
		exit(EXIT_FAILURE);
	}
	case 0:
		execv(av[0], av);
		// fall through
	default:
		wait(NULL);
	}
	free(av[1]);
	free(av[2]);
	free(av[3]);
}
