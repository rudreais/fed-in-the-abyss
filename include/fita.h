/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/include/fita.h
 * Path: /home/rudreais/prog/fed-in-the-abyss/include
 * Created Date: Tuesday, July 10th 2018, 1:34:37 pm
 * Author: rudreais
 *
 * Copyright (c) 2018 rudreais
 */

#pragma once

#include <ncurses.h>
#include "files.h"

char *read_line(int fd);

void gen_map(int level);

void print_map(WINDOW *win, Cursor *cam, files_t *maps);
