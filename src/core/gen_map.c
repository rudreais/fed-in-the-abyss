/**
 *
 *
 *
 */

#include  <time.h>
#include <stdlib.h>
#include <unistd.h> // execve()
#include <string.h>
#include <stdio.h>
#include "path.h"

extern char **environ;

char *get_seed(void)
{
	int seed;
	char *str_seed = malloc(sizeof(char) * 4);

	srand(time(NULL));
	seed = (int)(random() + 1) % 999;
	sprintf(str_seed, "%d", seed);
	return str_seed;
}

char *get_name(int level)
{
	char *str_lev = malloc(sizeof(char) * 5);

	sprintf(str_lev, "%d_1", level);
	return str_lev;
}

char *get_size(void)
{
	char *size = malloc(sizeof(char) * 5);

	sprintf(size, "%d", 512);
	return size;
}

void gen_map(int level)
{
	char *path = getpath("map_gen/rust_gen");
	char *exec = "map_generator";
	int len = (int) strlen(path) + (int) strlen(exec);
	char *full_path = malloc(sizeof(char) * (len + 1));
	char **newav = malloc(sizeof(char *) * 5);
	char *seed = get_seed();
	char *name = get_name(level);
	char *size = get_size();

	full_path[len] = '\0';
	for (int i = 0; i < (int) strlen(path); i++)
	    full_path[i] = path[i];
	strcat(full_path, exec);
	newav[0] = full_path;
	newav[1] = name;
	newav[2] = seed;
	newav[3] = size;
	newav[4] = NULL;
	execv(full_path, newav);
}
