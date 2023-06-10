/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:58:42 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:58:43 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

char *ftt_strdup(char *str)
{
  int i;
  int len;
  char *dup;
  
  i = 0;
  len = ftt_strlen(str);
  dup = (char *)malloc(sizeof(char) * len + 1);
  if (!dup)
    return (NULL);
  while (str[i])
  {
    dup[i] = str[i];
    i++;
  }
  dup[i] = '\0';
  return (dup);
}