/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:53 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 09:21:20 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void  print_unset_error(char *str)
{
  ftt_print_fd(2, "unset: ");
  ftt_print_fd(2, str);
  ftt_print_fd(2, ": not a valid identifier\n");
  shell->g_status = 1;
}

char **unset_cmd(char **env, char **argv)
{
  int i;
  int index;
  
  i = 1;
  if (!argv[1])
    return (0);
  
  while (argv[i])
  { 
    if (!env_compatible(argv[i]))
      print_unset_error(argv[i]);
    index = get_indice_env(env, argv[i]);
    if (index >= 0)
      env = unset_var_env(env, index);
    i++;
  }
  return (env);
}



