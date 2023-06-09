#include "../mini.h"

//khassni exit_code leçdim
//what above max long

void  exit_shell(t_mini *mini, int i)
{
  exit(i);
}

void  check_no_num(char *str)
{
  int i;

  i = 0;
  while (str[i] && ftt_isspace(str[i]))
    i++;
  if (str[i] == 0)
  {
    ftt_print_fd(2, "exit\nbash: exit: : numeric argument required\n");
    exit_shell(2);
  }
  i = 0;
  str = ftt_strtrim_space(str);
  while (str[i])
  {
    if (!ftt_isalpha(str[i]))
    {
      free (str);
      exit_shell(str,2);
    }
    i++;
  }
}


void  check_exit_ret(char *str)
{
  long n;
  
  check_no_num(str);
  n = ftt_atoi_l(str);
 n %= 256 ;
  ftt_print_fd(1, "exit");
  exit_shell(mini, n);
}

int exit_cmd(char **argv)
{

  if (argv[2] != 0)
    return (ftt_print_fd(2, "exit\nbash: exit: too many arguments\n"), 1);
  else if (argv[1] == 0)
    return (ftt_print_fd(1, "exit\n"), old_exit_code);
  else
    return (check_exit_ret(argv[1]), 16);
  return (69);
}