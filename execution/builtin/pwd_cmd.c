/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:17:27 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 08:33:00 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void  pwd_cmd(char **env, char **args)
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
}

int main(int ac, char **av, char **env)
{
  pwd_cmd(env, av);
}