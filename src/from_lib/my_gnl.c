/*
** EPITECH PROJECT, 2018
** gnl
** File description:
** gnl
*/

#include <stdlib.h>
#include <unistd.h>

static int check_buffer(char *buff)
{
	for (int i = 0; buff[i]; i++)
		if (buff[i] == '\n')
			return (0);
	return (1);
}

static int my_strlen2(char *str, char c)
{
	int length = 0;

	if (str == NULL)
		return (-1);
	for (; str[length] != '\0' || str[length] == c; length++)
		if (str[length] == c)
			return (length);
	return (-1);
}

static char *my_strjoin2(char *begin, char *end, int i)
{
	char *tmp;

	if (!(tmp = malloc (sizeof(char) * (i + 1))))
		return (NULL);
	tmp[i] = '\0';
	for (int k = 0; k < i - 1; k++)
		tmp[k] = begin[k];
	tmp[i - 1] = end[0];
	free(begin);
	return (tmp);
}

char *my_gnl(int fd)
{
	static char buffer[1];
	int i = 0;
	char *ret;
	int test = 0;

	if (!(ret = malloc (sizeof(char) * 1)))
		return (NULL);
	ret[0] = '\0';
	while ((test = read(fd, buffer, 1)) != 0) {
		i++;
		if (!check_buffer(buffer)) {
			buffer[0] = '\0';
			return (ret);
		}
		ret = my_strjoin2(ret, buffer, i);
	}
	if (!ret[0]) {
		free(ret);
		return (NULL);
	} else
		return (ret);
}
