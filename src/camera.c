#include "fita.h"

static void print_char(WINDOW *win, char c)
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	switch (c) {
	case '~':
		wattron(win, COLOR_PAIR(1));
		wprintw(win, "%c", c);
		wattroff(win, COLOR_PAIR(1));
		break;
	case '.':
		wattron(win, COLOR_PAIR(2));
		wprintw(win, "%c", c);
		wattroff(win, COLOR_PAIR(2));
		break;
	case '%':
		wattron(win, COLOR_PAIR(3));
		wprintw(win, "%c", c);
		wattroff(win, COLOR_PAIR(3));
		break;
	case '@':
		wattron(win, A_BOLD);
		wprintw(win, "@");
		wattroff(win, A_BOLD);
		break;
	default:
		wprintw(win, "%c", c);
		break;
	}
}

static void centered_map(WINDOW *win, cursor_t *cam, map_t **maps)
{
	map_t *map = maps[0];
	int cam_i = (cam->y - (N_LINES / 2)) - 1;
	int cam_j = (cam->x - (N_COLS / 2)) - 1;

	cam_i = (cam_i < 0) ? 0 : cam_i;
	cam_j = (cam_j < 0) ? 0 : cam_j;
	for (int i = 0; i < N_LINES; i++) {
		for (int j = 0; j < N_COLS; j++) {
			wmove(win, i, j);
			print_char(win, map->map[i + cam_i][j + cam_j]);
		}
	}
	refresh();
	wrefresh(win);
}

static enum direction border_cam(cursor_t *cam)
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

void camera(player_t *player, map_t **maps, properties_t *prop)
{
	int border; // define if fixed cam pos is used or not
	cursor_t fixed = player->pos;

	if ((border = border_cam(&player->pos)) != -1) {
		if (border == LEFT || border == RIGHT)
			fixed.y = player->pos.y;
		if (border == UP || border == DOWN)
			fixed.x = player->pos.x;
		centered_map(prop->win, &fixed, maps);
		refresh();
		wrefresh(prop->win);
	} else {
		fixed = player->pos_bak;
		centered_map(prop->win, &player->pos, maps);
	}
}
