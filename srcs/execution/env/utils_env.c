/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:53 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:18:42 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void  free_half(char **str, int i)
{
  while (i >= 0)
  {
    free(str[i]);
    i--;
  }
  free(str);
}

void  free_double_env(char **str)
{
  int i;

  i = -1;
  if (!str)
    return ;
  while (str[++i])
    free(str[i]);
  free(str);
}