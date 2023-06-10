/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:08 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 09:19:08 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

int  fti_strlen(char *str)
{
  int i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    i++;
  return (i);
}

int  get_flag(char *str)
{
  int j;

  j = 0;
  if (fti_strlen(str) < 2)
    return (0);
  if (str[j] != '-' && str[1] != 'n')
    return (0);
  j++;
  while (str[j])
  {
    if (str[j] != 'n')
        return (0);
    j++;
  }
  return (1);
}

int  cmd_echo(char **str)
{
  int i;
  int flag;

  flag = 0;
  i = 1;
  while (str[i] && get_flag(str[i]))
    {
      flag = 1;
      i++;
    }
  while(str[i])
  {
    if (str[i][0] != '0')
      ftt_print_fd(1, str[i]);
    ftt_print_fd(1, " ");
    i++;
  }
  if (flag == 0)
    ftt_print_fd(1, "\n");
  return (0);
}

// int main(int ac, char **av)
// {
//   cmd_echo(av);
// }
