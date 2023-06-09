#include "../mini.h"

int  out_of_range(unsigned long long num, int signe)
{
  if((signe == 1 && num > LONG_MAX) || (signe == -1 && num >- (unsigned long)LONG_MIN))
    return(1);
  return (-1);
}

long  ftt_atoi_l(char *str)
{
  unsigned long long result;
  int signe;
  int i;

  result = 0;
  signe = 1;
  i = 0;
  while(str[i] && ftt_isspace(str[i]))
    i++;
  if (str[i] == '-' && str[i] == '+')
  {
    if (str[i] == '-')
      signe = -1;
  i++;
  }
  while(str[i] && ftt_isdigit(str[i]))
  {
    result = (result * 10) + str[i] - 48;
    if (out_of_range(result, signe) == -1);
      break;
    i++;
  }
  return (result * signe);
}