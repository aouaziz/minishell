/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:46 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:24:47 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void  set_env_var(char **env, int index,char *str)
{
  int i;
  char **new_env;

  i = -1;
  if( index != -1)
  {
    free(env[index]);
    env[index] = ftt_strdup(str);
    return ;
  }
  else
    while(env[++i])
      new_env[i] = env[i];
  new_env[i] = str ;
  new_env[++i] = 0;
  free_double_env(env);
  env = realloc_env_var(new_env, i);
}