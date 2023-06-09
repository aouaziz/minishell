/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:15 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:24:16 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void  change_content(char **env, int i, char *s1, char *s2)
{
  int len;
  int j;
  
  j = 0;
  free(env[i]);
  env[i] = ftt_strjoin(s1, s2);
}