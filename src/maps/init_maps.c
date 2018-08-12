#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fita.h"
#include "my.h"

static char *get_file_content(int fd)
{
	struct stat file;
	char *buffer;
	ssize_t len;

	fstat(fd, &file);
	buffer = malloc(sizeof(char) * (file.st_size + 1));
	assert(buffer != NULL);
	len = read(fd, buffer, file.st_size);
	assert(len == file.st_size);
	buffer[file.st_size] = '\0';
	return buffer;
}

static map_t *create_map(char *filename)
{
	int fd;
	char *file;
	map_t *map = malloc(sizeof(map_t));

	assert(map != NULL);
	fd = open(filename, O_RDONLY);
	assert(fd != -1);
	file = get_file_content(fd);
	map->map = my_str_to_word_array(file, '\n');
	map->name = filename;
	free(file);
	return map;
}

static size_t get_maps_nb(map_t **tab)
{
	size_t i = 0;

	if (tab != NULL)
		for (; tab[i] != NULL; i++);
	return i;
}

static map_t **append_new_map(map_t **maps, char *filename)
{
	size_t i = 0;
	map_t **new = malloc(sizeof(map_t *) * (get_maps_nb(maps) + 2));

	assert(new != NULL);
	if (maps != NULL)
		for (; maps[i] != NULL; i++)
			new[i] = maps[i];
	new[i] = create_map(my_strcat("./maps/", filename));
	new[i + 1] = NULL;
	free(maps);
	return new;
}

map_t **init_maps(const char *path)
{
	DIR *dir = opendir(path);
	struct dirent *file;
	map_t **maps = NULL;

	assert(dir != NULL);
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] == '.' || !strcmp(file->d_name, "map_generator"))
			continue;
		maps = append_new_map(maps, file->d_name);
	}
	closedir(dir);
	return maps;
}
