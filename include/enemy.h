#pragma once

#include "fita.h"

typedef struct enemy_s enemy_t;
typedef struct charac_s charac_t;

struct charac_s {
    int level;
    int hp;
    int mp;
    int str;
    int def;
};

struct enemy_s {
    char name;
    cursor_t *pos;
    charac_t *charac;
};

void add_enemy(files_t *maps, enemy_t **enemies);
