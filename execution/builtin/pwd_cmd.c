/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:57 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:56:58 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

int  pwd_cmd(char **env, char **args)
{
  int i;
  char *pwd;
  
  i = 0;
  if (get_indice_env(env, "PWD=") != -1)
  {
    pwd = get_content_env(env, "PWD");
    while (pwd[i] != '=')
      i++;
    i++;
    if (!pwd[i])
    { 
      if (getcwd(pwd, 1000) != 0)
        ftt_print_fd(1, pwd);
    }
    else
      while(pwd[i])
        {
          write(1, &pwd[i], 1);
          i++;
        }
    write(1, "\n", 1);
  }
  free(pwd);
  return (0);
}

int main(int ac, char **av, char **env)
{
  pwd_cmd(env, av);
}