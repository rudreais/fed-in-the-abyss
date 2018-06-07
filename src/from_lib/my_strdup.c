/*
** EPITECH PROJECT, 2018
** lib
** File description:
** strdup
*/

#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *str)
{
	char *ret = malloc (sizeof(char) * (strlen(str) + 1));
	int i = 0;

	for (; str[i]; i++)
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}
