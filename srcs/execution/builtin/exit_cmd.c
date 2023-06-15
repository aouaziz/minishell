/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:02 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/14 21:39:12 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int get_ret_status(char *str)
{
  int i;

  i = 0;
  if (!str)
    return (1);
  if (str[0] == '-' || str[0] == '+')
      i++;
  while (str[i])
  {
    if (str[i] >= '0' && str[i] <= '9')
      i++;
  }
  if (str[i] != '\0')
    return (1);
  return (16);
}

void  exit_cmd(char **str)
{ 
  int ret ;
  
  ret = 0;
  if (shell->size == 1)
    printf("exit\n");
  if(!str[1])
    exit(shell->g_status);
  if (str[1])
  {
    ret = get_ret_status(str[1]);
    if (ret == 1)
      shell->g_status = ft_atoi(str[1]);
  }
  if (str[1] != NULL && str[2] != NULL && ret != 1)
  {
    printf ("bash: exit: too many arguments\n");
    shell->g_status = 1;
  }
  if (ret == 1)
    printf ("bash: exit: %s:numeric argument required\n", str[1]);
  exit(shell->g_status);
}