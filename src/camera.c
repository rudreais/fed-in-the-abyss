#include "fita.h"

enum direction border_cam(cursor_t *cam)
{
	int width = GET_WIDTH;
	int height = GET_HEIGHT;

	if ((cam->x < ((width / 2) + 1) && cam->y < ((height / 2) + 1)) ||
		(cam->x < ((width / 2) + 1) && cam->y > MAP_SIZE - (height / 2)) ||
		(cam->x > MAP_SIZE - (width / 2) && cam->y < ((height / 2) + 1)) ||
		(cam->x > MAP_SIZE - (width / 2) && cam->y > MAP_SIZE - (height / 2)))
		return -1;
	if (cam->x < ((width / 2) + 1))
		return RIGHT;
	if (cam->x > MAP_SIZE - (width / 2))
		return LEFT;
	if (cam->y < ((height / 2) + 1))
		return UP;
	if (cam->y > MAP_SIZE - (height / 2))
		return DOWN;
	return -1;
}

void camera(player_t *player, WINDOW *win, map_t **maps)
{
	int border; // define if fixed cam pos is used or not
	cursor_t fixed = player->pos;

	if ((border = border_cam(&player->pos)) != -1) {
		if (border == LEFT || border == RIGHT)
			fixed.y = player->pos.y;
		if (border == UP || border == DOWN)
			fixed.x = player->pos.x;
		centered_map(win, &fixed, maps);
		refresh();
		wrefresh(win);
	} else {
		fixed = player->pos_bak;
		centered_map(win, &player->pos, maps);
	}
}
