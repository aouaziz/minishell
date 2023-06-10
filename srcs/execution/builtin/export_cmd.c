/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:59 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:23:27 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char  *get_new_env_keys(char *str)
{
  int i;
  int start;
  
  i = 0;
  while(str[i] != '=')
    i++;
  return (ftt_substr(str, 0, i + 1));
}

char **export_cmd(char **env, char **argv)
{
  int i;
  char *tmp;
  int itmp;
  
  i = 1;
  if (argv[i] == 0)
    return ((void)env_cmd(env, argv), env);
  while(argv[i])
  {
    printf ("dezet hnna\n");
    if (!env_compatible(argv[i]))
      print_err_env(argv[i]);
    else if(ftt_strrchr(argv[i], '=') != NULL)
    {
      tmp = get_new_env_keys(argv[i]);
      itmp = get_indice_env(env, tmp);
      set_env_var(env, itmp, argv[i]);
      free(tmp);
    }
    i++;
  }
  return (env);
}

// int main(int ac, char **av, char **env)
// {
//   char **str;
//   int i = -1;
//   str = export_cmd(env, av);
//   //while (str[++i])
//     //printf ("%s\n", str[i]);
// }