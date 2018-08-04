#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

char *my_snprintf(const char *format, ...)
{
	va_list ap;
	char *new;
	int len;

	assert(format != NULL);
	va_start(ap, format);
	len = vsnprintf(NULL, 0, format, ap);
	assert(len > 0);
	new = malloc(sizeof(char) * (len + 1));
	assert(new != NULL);
	va_end(ap);
	va_start(ap, format);
	vsnprintf(new, len + 1, format, ap);
	va_end(ap);
	return new;
}
