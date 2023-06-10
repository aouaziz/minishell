/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:15 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:48:08 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void  change_content(char **env, int i, char *s1, char *s2)
{
  int j;
  
  j = 0;
  free(env[i]);
  env[i] = ftt_strjoin(s1, s2);
}