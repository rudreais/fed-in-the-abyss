#include <assert.h>
#include <stdlib.h>
#include <string.h>

size_t word_counter(char *str, char delim)
{
	size_t i = 0;
	size_t nb = 0;

	if (str[0] == '\0')
		return (1);
	for (; *str == delim; str++);
	for (i = strlen(str) - 1; i > 0 && str[i] == delim; i--)
		str[i] = '\0';
	for (; *str != '\0'; str++) {
		if (*str == delim)
			nb++;
		for (; *str == delim; str++);
	}
	return (nb + 1);
}

char *get_word(char *line, char delim)
{
	size_t i = 0;

	if (*line == '\0')
		return (strdup(line));
	while (line[i] != delim && line[i] != '\0')
		i++;
	return (strndup(line, i));
}

char **my_str_to_word_array(char *line, char delim)
{
	size_t i = 0;
	size_t nb_word = 0;
	char **tab;

	if (!line)
		return (NULL);
	nb_word = word_counter(line, delim);
	tab = malloc(sizeof(char *) * (nb_word + 1));
	assert(tab != NULL);
	for (; i < nb_word; i++) {
		for (; *line == delim; line++);
		tab[i] = get_word(line, delim);
		assert(tab[i] != NULL);
		for (; *line != delim && *line; line++);
	}
	tab[i] = NULL;
	return (tab);
}
