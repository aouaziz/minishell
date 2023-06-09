/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_var_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:49 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:24:50 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void  unset_var_env(char **env, int index)
{
  int i;
  int count;
  char **new_env;

  count = 0;
  i = 0;
  while(env[i] && i != index)
  {
    new_env[i] = env[i];
    i++;
    count++;
  }
  while (env[i + 1])
  {
    new_env[i] = env[i + 1];
    i++;
    count++;
  }
  new_env[i] = 0;
  free_double_env(env);
  env = realloc_env_var(new_env, count);
}