#include "../mini.h"

int  unset_cmd(char **env, char **argv)
{
  int i;
  int index;
  
  i = 1;
  if (!argv[1])
    return (0);
  while (argv[i])
  {
    index = get_indice_env(env, argv[i]);
    if (index >= 0)
      unset_var_env(env, index);
    i++;
  }
  if (write(1, "\n", 1) == -1)
    return (-1);
  return (0);
}