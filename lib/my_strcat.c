#include <assert.h>
#include <stdlib.h>
#include <string.h>

/**
 * my_strcat() function appends the src string and the dest string into a new
 * string create using malloc(3).
 * \param dest : pointer to first string
 * \param src : pointer to second string
 * \return A pointer to the new string.
 */

char *my_strcat(char *dest, char *src)
{
	size_t i = 0;
	size_t len = ((dest ? strlen(dest) : 0) + (src ? strlen(src) : 0));
	char *new = malloc(sizeof(char) * (len + 1));

	assert(new != NULL);
	if (dest != NULL)
		for (; dest[i] != '\0'; i++)
			new[i] = dest[i];
	if (src != NULL)
		for (; *src != '\0'; i++, src++)
			new[i] = *src;
	new[i] = '\0';
	return new;
}
