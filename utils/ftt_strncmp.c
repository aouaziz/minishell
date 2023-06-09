#include "../mini.h"

int  ftt_strncmp(char *s1, char *s2, int n)
{
  int i;

  i = 0;
  while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
    i++;
  if (s1[i] == 0 && s2[i] == 0)
    return (0);
  if (i == n)
    return (0);
  return (1);
}