#pragma once

typedef struct string_s String;

struct string_s {
    char *s;
	void (*StringInit)(String *, const char *);
	void (*StringDestroy)(String *);
	void (*assign_s)(String *, const String *);
	void (*assign_c)(String *, const char *);
	void (*append_c)(String *, const char *);
	void (*append_s)(String *, const String *);
};

void StringInit(String *self, const char *s);
void StringDestroy(String *self);

void assign_s(String *self, const String *str);
void assign_c(String *self, const char *s);

void append_c(String *self, const char *ap);
void append_s(String *self, const String *ap);