/*
** RUDREAIS, 06/13/18
** lib/objects
** File description:
** maps
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "libobjects.h"

char *read_line(int fd);

char *path = "/home/rudreais/fed-in-the-abyss/maps/1_1";

map_t create_map(void)
{
  map_t map;
  int fd = open(path, O_RDONLY);
  char *line;

  map.ymax = 0;
  map.design = malloc(sizeof(char *));
  while ((line = read_line(fd)) != NULL) {
    map.design = realloc(map.design, (map.ymax + 1));
    map.ymax++;
    map.design[map.ymax - 1] = malloc(sizeof(char) * strlen(line));
  }
  return map;
}
