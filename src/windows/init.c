/*
** RUDREAIS, 05/27/18
** roguelike
** File description:
** map generator header
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include "board.h"
#include "character.h"

char *my_gnl(int fd);
char *my_strdup(char *str);

void get_map(map_t *map)
{
	char **map_design = malloc(sizeof(char *) * 1);
	char *home = getenv("HOME");
	char *path = strcat(home, (TMP_PATH));
	int fd;
    char * line = NULL;
	int i = 1;

	fd = open(path, O_RDONLY);
	if (fd < 0) {
		exit (EXIT_FAILURE);
		endwin();
	}
	while ((line = my_gnl(fd)) != NULL) {
		map_design = realloc(f_floor->design, sizeof(char *) * (i + 1));
		[i - 1] = my_strdup(line);
		i++;
		free(line);
	}
	map_design[i - 1] = NULL;
	map->design = map_design;
	map->ymax = i - 1;
}

void init_curse(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();
}