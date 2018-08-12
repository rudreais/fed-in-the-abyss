/**
 *
 *
 *
 */

#include "fita.h"

void screen_charac(player_t *player)
{
	move(0, N_COLS);
	printw("Level: %d\n", player->charac.level);
	move(1, N_COLS);
	printw("hp:%d/%d\n", player->charac.hp, player->charac.hp_max);
	move(2, N_COLS);
	printw("mp:%d\n", player->charac.mp);
	move(3, N_COLS);
	printw("str:%d\n", player->charac.str);
	move(4, N_COLS);
	printw("def:%d\n", player->charac.def);
}
