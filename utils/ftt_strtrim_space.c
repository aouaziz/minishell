#include "../mini.h"

char *ftt_strtrim_space(char *str)
{
  int i;
  int start;
  int end;
  
  start = 0;
  end = ftt_strlen(str) - 1;
  while (str[start] && ftt_isspace(str[start]))
    start++;
  while(str[end] && ftt_isspace(str[end]))
    end--;
  return (ftt_substr(str, start, end - start + 1));
}
