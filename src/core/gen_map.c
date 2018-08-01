/**
 *
 *
 *
 */

#include <sys/wait.h>
#include  <time.h>
#include <stdlib.h>
#include <unistd.h> // execve()
#include <string.h>
#include <stdio.h>
#include "path.h"

extern char **environ;

static char *get_seed(void)
{
	int seed;
	char *str_seed = malloc(sizeof(char) * 4);

	srand(time(NULL));
	seed = (int)(random() + 1) % 999;
	sprintf(str_seed, "%d", seed);
	return str_seed;
}

static char *get_name(int level)
{
	char *str_lev = malloc(sizeof(char) * 5);

	sprintf(str_lev, "%d_1", level);
	return str_lev;
}

static char *get_size(void)
{
	char *size = malloc(sizeof(char) * 5);

	sprintf(size, "%d", 512);
	return size;
}

void move_file(int level)
{
	char *path_map = getpath("maps");
	char *map = get_name(level);
	char **newav = malloc(sizeof(char *) * 4);
	char *cmd = "mv";

	newav[0] = cmd;
	newav[1] = map;
	newav[2] = path_map;
	newav[3] = NULL;
	if (fork() == 0)
		execvp(cmd, newav);
	else
		wait(NULL);
	free(path_map);
	free(map);
	free(newav);
}

void create_dir(void)
{
		char *path = getroot();
		char *filename = "/maps";
		int len = strlen(path) + strlen(filename);

		path = realloc(path, sizeof(char) * (len + 1));
		for (int i = strlen(path), j = 0; i < len; i++, j++)
				path[i] = filename[j];
		path[len] = '\0';
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
	pid_t child;

	full_path[len] = '\0';
	for (int i = 0; i < (int) strlen(path); i++)
	    full_path[i] = path[i];
	for (int i = 0; i < (int) strlen(exec); i++)
		full_path[strlen(path) + (i)] = exec[i];
	newav[0] = full_path;
	newav[1] = name;
	newav[2] = seed;
	newav[3] = size;
	newav[4] = NULL;
	if ((child = fork()) == 0)
		execv(full_path, newav);
	else
		wait(NULL);
	create_dir();
	move_file(level);
	free(full_path);
	free(newav);
	free(seed);
	free(name);
	free(size);
	free(path);
}
