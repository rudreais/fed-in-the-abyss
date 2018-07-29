/**
 *
 *
 *
 */

#include <stdlib.h>
#include <time.h>
#include "fita.h"
#include "enemy.h"

charac_t possible_charac[] = {
   {1, 10, 4, 3, 1}, // R
   {1, 14, 2, 5, 0}, // W
   {1,  8, 5, 1, 3}, // Z
   {1, 10, 3, 2, 2}, // O
   {-1, -1, -1, -1, -1} // null
};

enemy_t possible_enemies[] = {
    // {char name, ptr pos, ptr pos_bak, ptr charac}
    {'R', NULL, NULL, &possible_charac[0]},
    {'W', NULL, NULL, &possible_charac[1]},
    {'Z', NULL, NULL, &possible_charac[2]},
    {'O', NULL, NULL, &possible_charac[3]},
    {'\0', NULL, NULL, NULL}
};

void enemy_turn(cursor_t *player, enemy_t *enemy, char **map)
{
    int e_key = -1; // "emulated" key
    cursor_t pos_player;

    if (enemy->pos->x > player->x) {
        e_key = KEY_LEFT; 
    } else if (enemy->pos->y > player->y) {
        e_key = KEY_UP;
    } else if (enemy->pos->x < player->x) {
        e_key = KEY_RIGHT;
    } else if (enemy->pos->y < player->y) {
        e_key = KEY_DOWN;
    }
    pos_player = move_charac(e_key, enemy->pos, enemy->pos_bak, map);
    (void)pos_player;
}

void assign_enemy(char **map, char **old_state, enemy_t *enemy)
{
    map[enemy->pos_bak->y][enemy->pos_bak->x] = old_state[enemy->pos->y][enemy->pos->x];
    map[enemy->pos->y][enemy->pos->x] = enemy->name;
    cursor_copy(enemy->pos_bak, enemy->pos);
}

void add_enemy(enemy_t **enemies)
{
    int index = 0;
    enemy_t *enemy = malloc(sizeof(enemy_t));

    srand(time(NULL));
    index = rand() % 4; 
    enemy->name = possible_enemies[index].name;
    enemy->charac = possible_enemies[index].charac;
    enemy->pos = malloc(sizeof(cursor_t));
    enemy->pos->x = 50;
    enemy->pos->y = 20;
    enemy->pos_bak = malloc(sizeof(cursor_t));
    enemy->pos_bak->x = 50;
    enemy->pos_bak->y = 20;
    enemies[0] = enemy;
}
