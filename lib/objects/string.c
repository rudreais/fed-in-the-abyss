/*
 * Filename: /home/rudreais/prog/fed-in-the-abyss/lib/objects/string.c
 * Path: /home/rudreais/prog/fed-in-the-abyss/lib/objects
 * Created Date: Tuesday, July 10th 2018, 1:04:08 pm
 * Author: rudreais
 * 
 * Copyright (c) 2018 Your Company
 */

#include <string.h>
#include <stdlib.h>
#include "o_string.h"

void assign_s(String *this, const String *str)
{
    this->StringDestroy(this);
    this->StringInit(this, str->s);
}

void assign_c(String *this, const char *s)
{
    this->StringDestroy(this);
    this->StringInit(this, s);
}

void append_c(String *this, const char *ap)
{
    int len = strlen(this->s) + strlen(ap);
    int index = strlen(this->s);
    
    this->s = realloc(this->s, sizeof(char) * (len + 1));
    this->s[len] = '\0';
    for (int j = 0, i = index; i < len; i++)
        this->s[i] = ap[j++];
}

void append_s(String *this, const String *ap)
{
    this->append_c(this, ap->s);    
}

void StringDestroy(String *self)
{
    free(self->s);
}

void StringInit(String *self, const char *str)
{
    int len = strlen(str);

    self->s = malloc(sizeof(char) * (len + 1));
    self->s[len] = '\0';
    for (int i = 0; i < len; i++)
        self->s[i] = str[i];

    self->StringDestroy = StringDestroy;
    self->append_c = append_c;
    self->append_s = append_s;
    self->assign_c = assign_c;
    self->assign_s = assign_s;
}