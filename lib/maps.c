#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include "maps.h"

char *read_line(int fd);

static void files_append(file_t *file, const char *path_to_dir, const char *name)
{
	int len = strlen(path_to_dir) + strlen(name);
	char *full_path = malloc(sizeof(char) * (len + 1));
	int fd;
	char *line;
	int nlines;

	file->map = malloc(sizeof(char *));
	for (int i = 0; i < (int)strlen(path_to_dir); i++)
		full_path[i] = path_to_dir[i];
	strcat(full_path, name);
	fd = open(full_path, O_RDONLY);
	while ((line = read_line(fd)) != NULL) {
		nlines++;
		file->map = realloc(file->map, sizeof(char *) * nlines);
		file->map[nlines - 1] = line;
	}
	file->y_len = nlines;
}

void files_init(files_t *files, const char *path_to_dir)
{
	DIR *dir = opendir(path_to_dir);
	struct dirent *file;
	int i = 0;

	files->size = 0;
	files->files = malloc(sizeof(file_t));
	while ((file = readdir(dir)) != NULL) {
		if (file->d_name[0] != '.') {
			files->files = realloc(files->files, sizeof(file_t) * i + 1);
			files->size++;
			files->files[i] = malloc(sizeof(file_t));
			files_append(files->files[i++], path_to_dir, file->d_name);
		}
	}
}
