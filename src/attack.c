#include "fita.h"

// enemy_t turn => see include/enemy.h for details
void attack(enemy_t **enemies, cursor_t *defender, enemy_t *turn, player_t *player)
{
	cursor_t backup = {
		.x = defender->x,
		.y = defender->y
	};

	if (turn->name != '@') {
		player->charac.hp--;
		return;
	}
	for (int i = 0; enemies[i]; i++) {
		if (enemies[i]->pos.x == backup.x && enemies[i]->pos.y == backup.y)
			enemies[i]->charac.hp = enemies[i]->charac.hp - turn->charac.str;
	}
}
