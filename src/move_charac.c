#include "fita.h"
#include "enemy.h"

cursor_t move_charac(int key, cursor_t *pos, cursor_t *cam, char **map)
{
	char c_char;
	cursor_t ret = {
		.x = -1,
		.y = -1
	};

	switch (key) {
	case KEY_LEFT:
		pos->x--;
		break;
	case KEY_RIGHT:
		pos->x++;
		break;
	case KEY_UP:
		pos->y--;
		break;
	case KEY_DOWN:
		pos->y++;
		break;
	default:
		break;
	}
	pos->x = (pos->x < 0) ? 0 : pos->x;
	pos->x = (pos->x > MAP_SIZE - 1) ? MAP_SIZE - 1 : pos->x;
	pos->y = (pos->y < 0) ? 0 : pos->y;
	pos->y = (pos->y > MAP_SIZE - 1) ? MAP_SIZE - 1 : pos->y;
	for (int i = 0; i < enemies_nb; i++) {
		c_char = map[pos->y][pos->x];
		if (c_char == possible_enemies[i].name || c_char == '@') {
			ret.x = pos->x;
			ret.y = pos->y;
			pos->x = cam->x;
			pos->y = cam->y;
			return ret;
		}
	}
	return ret;
}
