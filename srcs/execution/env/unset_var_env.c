/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_var_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:49 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:18:42 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int get_alloc_long(char **env, int index)
{
  int i;
  int count;

  i = 0;
  count = 0;
  while (env[i] && i != index)
  {
   i++;
   count++; 
  }
  while (env[i + 1])
  {
    i++;
    count++;
  }
  return (count);
}

char **unset_var_env(char **env, int index)
{
  int i;
  int count;
  char **new_env;

  count = get_alloc_long(env ,index);
  i = 0;
  new_env = (char **)malloc(sizeof(char *) * count + 1);
  if (!new_env)
    return (ftt_print_fd(2, "can't allocae somewhere\n"), env);
  while(env[i] && i != index)
  {
    new_env[i] = ftt_strdup(env[i]);
    i++;
  }
  while (env[i + 1])
  {
    new_env[i] = ftt_strdup(env[i + 1]);
    i++;
  }
  new_env[i] = 0;
  return (new_env);
}