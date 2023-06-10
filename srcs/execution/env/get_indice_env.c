/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_indice_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:34 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:24:35 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int  get_indice_env(char **env, char *path)
{
  int i;
  int len;
  
  i = 0;
  len = ftt_strlen(path);
  while(env[i])
  {
    if (ftt_strncmp(env[i], path, len) == 0)
      return (i);
    i++;
  }
  return (-1);
}