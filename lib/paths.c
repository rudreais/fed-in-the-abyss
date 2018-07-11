#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include "path.h"

static int is_dir(const char *path)
{
    DIR *dir = opendir(path);
    struct dirent *act_dir;

    if (dir == NULL)
	return -1;
    while ((act_dir = readdir(dir)) != NULL) {
	if (strcmp(act_dir->d_name, DIRECTORY) == 0) {
	    free(dir);
	    return 1;
	}
    }
    return 0;
}

char *getroot(void)
{
    char *buff = malloc(sizeof(char) * 4096);
    char *tmp = NULL;

    getcwd(buff, 4096);
    if (is_dir(buff)) {
	free(tmp);
	return buff;
    }
    for (int i = strlen(buff); i >= 0; i--) {
	if (i > 0 && buff[i] == '/') {
	    free(tmp);
	    tmp = malloc(sizeof(char) * (i + 1));
	    tmp[i] = '\0';
	    strncpy(tmp, buff, i);
	    if (is_dir(tmp)) {
		free(buff);
		return tmp;
	    }
	}
    }
    return NULL;
}

char *getpath(const char *directory)
{
    char *root = getroot();
    int length = (strlen(root) + strlen(directory));
    char *path = malloc(sizeof(char) * (length + 2));

    for (int i = 0; i < (int)strlen(root); i++) {
	path[i] = root[i];
    }
    path[strlen(root)] = '/';
    path[strlen(root) + 1] = '\0';
    free(root);
    strcat(path, directory);
    path[length + 1] = '\0';
    return path;
}
