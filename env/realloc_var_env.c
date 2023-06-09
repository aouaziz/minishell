/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_var_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:44 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:24:45 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

char **realloc_env_var(char **env, int count)
{
  int i;
  char **new_env;
  
  i = 0;
  new_env = (char **)malloc(sizeof(char *) * (count + 1));
  if (!new_env)
    return (0);
  while (env[i])
  {
    new_env[i] = ftt_strdup(env[i]);
    if(new_env[i])
      return (free_half(new_env ,i), NULL);
    i++;
  }
  new_env[i] = 0;
  return (new_env);
}