/**
 ** rudreais
 ** main
 **
 */

#include <stdio.h>
#include "libobjects.h"

int main(void)
{
  dim_t dim = create_dim(50, 70);

  printf("width=%d\nheight=%d\n", dim.width, dim.height);
  printf("--------------\n");
  modify_dim(&dim, 100, 40);
  printf("width=%d\nheight=%d\n", dim.width, dim.height);
  return 0;
}
