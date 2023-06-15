/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:21 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:18:42 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int  count_env(char **env)
{
  int count;

  count = -1;
  while(env[++count])
    count++;
  return (count);
}
