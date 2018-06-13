#include <stdlib.h>
#include <unistd.h>

char *read_line(int fd)
{
  char *line = malloc(sizeof(char));
  char buffer[1];
  int pos = 0;
  int size = 1;

  buffer[0] = '\0';
  while (size > 0) {
    size = read(fd, buffer, 1);
    pos++;
    if (buffer[0] != '\n') {
      line = realloc(line, sizeof(char) * (pos + 1));
      line[pos - 1] = buffer[0];
      line[pos] = '\0';
    } else {
      return line;
    }
  }
  return NULL;
}
