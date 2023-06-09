#include "../mini.h"

int ftt_isalnum(char c)
{
  if (ftt_isalpha(c) || ftt_isdigit(c))
    return (1);
  return (0);
}