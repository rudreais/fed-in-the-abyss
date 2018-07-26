#include <stdlib.h>
#include <string.h>
#include "cursor.h"
#include "fita.h"

char **cpy_state(file_t *map)
{
	char **old_state = malloc(sizeof(char *) * map->y_len);
	int length = 0;

	for (int i = 0; i < map->y_len; i++) {
		length = strlen(map->map[i]);
		old_state[i] = malloc(sizeof(char) * (length + 1));
		old_state[i][length] = '\0';
		strcpy(old_state[i], map->map[i]);
	}
	return old_state;
}

void assign_player(char **map, char **old_state, cursor_t *charac, cursor_t *cam)
{
    map[cam->y][cam->x] = old_state[cam->y][cam->x];
    map[charac->y][charac->x] = '@';
}

