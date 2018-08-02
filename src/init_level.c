#include <stdlib.h>
#include "files.h"
#include "fita.h"
#include "path.h"

void init_level(files_t *maps, char ***old_state)
{
	char *path = getpath("maps");

	files_init(maps, path);
	free(path);
	*old_state = cpy_state(maps->files[0]);
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	move(0, 0);
}
