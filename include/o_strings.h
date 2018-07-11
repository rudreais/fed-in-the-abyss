#pragma once

#include "o_string.h"

typedef struct strings_s Strings;

struct strings_s {
    String **array;
    unsigned int size;
    void(*StringsInit)(Strings *);
    void(*push_back)(Strings *, const String *);
    void(*push_front)(Strings *, const String *);
};

void StringsInit(Strings *self);

void push_back(Strings *self, const String *to_add);
void push_front(Strings *self, const String *to_add);
