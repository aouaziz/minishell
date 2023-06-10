/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_strtrim_space.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:58:54 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:18:42 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *ftt_strtrim_space(char *str)
{
  int i;
  int start;
  int end;
  
  start = 0;
  end = ftt_strlen(str) - 1;
  while (str[start] && ftt_isspace(str[start]))
    start++;
  while(str[end] && ftt_isspace(str[end]))
    end--;
  return (ftt_substr(str, start, end - start + 1));
}
