#include <stdlib.h>
#include <string.h>
#include "cursor.h"
#include "fita.h"
#include "enemy.h"

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

// SHOULD BE CALLED ONLY ONCE
player_t *create_player()
{
	cursor_t *charac = malloc(sizeof(cursor_t)); // player pos
	cursor_t *cam = malloc(sizeof(cursor_t)); // cam pos
    player_t *player = malloc(sizeof(player_t));

    player->charac = malloc(sizeof(charac_t));
    player->charac->level = 1;
    player->charac->hp = 10;
    player->charac->mp = 10;
    player->charac->str = 5;
    player->charac->def = 3;
    player->name = '@';
	cursor_modify(charac, (GET_WIDTH / 2) + 1, (GET_HEIGHT / 2) + 1);
	cursor_copy(cam, charac); // before the first iteration, copy everything
    player->pos = charac;
    player->pos_bak = cam;
    return player;
}
