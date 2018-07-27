#pragma once

typedef struct file_s file_t;

// SOON WILL BE DEPRECATED
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

// SOON WILL BE DEPRECATED
/**
 * @param files pointer, path to the directory to init
 * @return nothing
 * @purpose initialize files and keep in memory the maps
 */
void files_init(files_t *files, const char *path_to_dir);

/**
 * @param files pointer
 * @return nothing
 * @purpose destroy files pointer
 */
void destroy_files(files_t *files);
