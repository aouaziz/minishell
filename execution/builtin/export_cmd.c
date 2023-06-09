#include "../mini.h"

char  *get_new_env_keys(char *str)
{
  int i;
  int start;
  
  i = 0;
  while(str[i] != '=')
    i++;
  //i++;
  //start = i;
  //if (!str[i])
    //return (ftt_strdup(""));
  //else
    //while(str[i])
      //i++;
  return (ftt_substr(str, 0, i + 1));
}

int  export_cmd(char **env, char **argv)
{
  int i;
  int returno;
  char *tmp;
  int itmp;
  
  returno = 0;
  i = 1;
  if (argv[i] == 0)
    return (env_cmd(env, argv));
  while(argv[i])
  {
    if (!env_compatible(argv[i]))
    {
      print_err_env(argv[i]);
      returno = 1;
    }
    else if(ftt_strrchr(argv[i], '=') != NULL)
    {
      tmp = get_new_env_keys(argv[i]);
      //tmp = before_the_equal(argv[i]);
      itmp = get_indice_env(env, tmp);
      set_env_var(env, itmp, argv[i]);
      free(tmp);
    }
    i++;
  }
  return (returno);
}