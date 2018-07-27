/**
 *
 *
 *
 */

#include <stdlib.h>
#include <time.h>
#include "fita.h"
#include "enemy.h"

enemy_t possible_enemies[] = {
    // {char name, ptr pos, ptr charac}
    {'R', NULL, NULL},
    {'W', NULL, NULL},
    {'Z', NULL, NULL},
    {'O', NULL, NULL},
    {'\0', NULL, NULL}
};


void add_enemy(files_t *maps, enemy_t **enemies)
{
    int index = 0;
    enemy_t *enemy = malloc(sizeof(enemy_t));

    srand(time(NULL));
    index = rand() % 4; 
    enemy->name = possible_enemies[index].name;
    enemy->charac = NULL;
    enemy->pos = malloc(sizeof(cursor_t));
    enemy->pos->x = 50;
    enemy->pos->y = 20;
    enemies[0] = enemy;
    maps->files[0]->map[enemy->pos->y][enemy->pos->x] = enemy->name;
}
