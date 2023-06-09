/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:53 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 11:02:11 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

int unset_cmd(char **env, char **argv)
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
      env = unset_var_env(env, index);
    i++;
  }
  if (write(1, "\n", 1) == -1)
    return (-1);
  return (0);
}


int main(int ac, char **av, char **env)
{
  char **str;

  str = ftt_strdup_2(env);
  unset_cmd(str, av);
  int i = -1;
  while (str[++i])
   printf ("--%s---\n", str[i]);
    return(0);
}

