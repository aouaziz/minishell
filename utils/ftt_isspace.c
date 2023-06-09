#include "../mini.h"

int ftt_isspace(char c)
{
  if (c == ' ' || (c <= 13 && c >= 9))
    return (1);
  return (0);
}