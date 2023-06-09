#include "../mini.h"

void  ftt_print_fd(int fd, char *str)
{
  int i;

  i = -1;
  while(str[++i])
    write(fd, &str[i], 1);
}