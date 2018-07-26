#pragma once

#include "fita.h"

typedef struct enemy_s enemy_t;

struct enemy_s {
    char name;
    cursor_t pos;
};

void add_enemy(files_t *maps);
