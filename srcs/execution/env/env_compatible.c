/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_compatible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:25 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:48:30 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../../includes/minishell.h"

int  env_compatible(char *str)
{
  int i;

  i = 0;
  if(!ftt_isalpha(str[0]) && str[i] != '_')
    return (0);
  i++;
  while(str[i] && str[i] != '=')
  {
    if (!ftt_isalnum(str[i]) && str[i] != '_')
      return(0);
    i++;
  }
  return (1);
}