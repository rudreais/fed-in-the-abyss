#include <assert.h>
#include <stdlib.h>
#include <string.h>

static size_t my_tablen(char **tab)
{
	size_t i = 0;

	if (tab != NULL)
		for (; tab[i] != NULL; i++);
	return i;
}

/**
 * my_tabdup() function return a pointer to a new string array which is a
 * duplicate of the string array tab.
 * \param tab : A string array
 * \return A pointer to duplicated string array.
 */

char **my_tabdup(char **tab)
{
	size_t i = 0;
	size_t len = my_tablen(tab);
	char **new = malloc(sizeof(char *) * (len + 1));

	assert(new != NULL);
	for (; i < len; i++) {
		new[i] = strdup(tab[i]);
		assert(new[i] != NULL);
	}
	new[i] = NULL;
	return new;
}
