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
    {'R', NULL, NULL, NULL},
    {'W', NULL, NULL, NULL},
    {'Z', NULL, NULL, NULL},
    {'O', NULL, NULL, NULL},
    {'\0', NULL, NULL, NULL}
};

void enemy_turn(enemy_t *enemy)
{
    enemy->pos->x++;
}

void assign_enemy(char **map, char **old_state, enemy_t *enemy)
{
    map[enemy->pos_bak->y][enemy->pos_bak->x] = old_state[enemy->pos->y][enemy->pos->x];
    map[enemy->pos->y][enemy->pos->x] = enemy->name;
    cursor_copy(enemy->pos_bak, enemy->pos);
}

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
    enemy->pos_bak = malloc(sizeof(cursor_t));
    enemy->pos_bak->x = 50;
    enemy->pos_bak->y = 20;
    enemies[0] = enemy;
}
