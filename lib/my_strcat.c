#include <assert.h>
#include <stdlib.h>
#include <string.h>

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
