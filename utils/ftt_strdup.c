#include "../mini.h"

char *ftt_strdup(char *str)
{
  int i;
  int len;
  char *dup;
  
  i = 0;
  len = ftt_strlen(str);
  dup = (char *)malloc(sizeof(char) * len + 1);
  if (!dup)
    return (NULL);
  while (str[i])
  {
    dup[i] = str[i];
    i++;
  }
  dup[i] = '\0';
  return (dup);
}