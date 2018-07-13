#pragma once

typedef struct file_s file_t;
typedef struct files_s files_t;

struct file_s {
	char **map;
	char *name;
	int y_len;
};

struct files_s {
	file_t **files;
	int size;
};

void files_init(files_t *files, const char *path_to_dir);
