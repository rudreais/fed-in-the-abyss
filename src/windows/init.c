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

void get_map(floor_t *f_floor)
{
	char *home = getenv("HOME");
	char *path = strcat(home, (TMP_PATH));
	int fd;
    char * line = NULL;
	int i = 1;

	f_floor->design = calloc(1, sizeof(char *));
	fd = open(path, O_RDONLY);
	if (fd < 0) {
		exit (EXIT_FAILURE);
		endwin();
	}
	while ((line = my_gnl(fd)) != NULL) {
		f_floor->design = realloc(f_floor->design, sizeof(char *) * (i + 1));
		f_floor->design[i - 1] = my_strdup(line);
		i++;
		free(line);
	}
	f_floor->design[i - 1] = NULL;
	f_floor->ymax = i - 1;
}

void init_dungeon(dungeon_t *dungeon)
{
	dungeon->floors = malloc(sizeof(floor_t *) * 1);
	dungeon->floors[0] = malloc(sizeof(floor_t));
	dungeon->floors[0]->design = calloc(1, sizeof(char *));
	dungeon->floors[0]->chars = malloc(sizeof(character_t *) * 1);
	dungeon->floors[0]->chars[0] = malloc(sizeof(character_t));
}

void init_curse(void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	refresh();
}