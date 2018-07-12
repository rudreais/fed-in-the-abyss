#include <stdlib.h>
#include "o_strings.h"

static String *cpy_S(const String *to_add)
{
  String *new_ptr = malloc(sizeof(String));

  new_ptr->StringInit = StringInit;
  new_ptr->StringInit(new_ptr, to_add->s);
  return new_ptr;
}

void push_back(Strings *self, const String *to_add)
{
    self->size++;
    self->array = realloc(self->array, sizeof(String *) * self->size);
    self->array[self->size - 1] = cpy_S(to_add);
}

void StringsInit(Strings *self)
{
    self->array = malloc(sizeof(String *) * 1);
    self->size = 0;
    self->push_back = push_back;
}
