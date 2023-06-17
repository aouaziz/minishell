/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:53 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/17 09:28:08 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *get_key(char *str)
{
  int i;

  i = 0;
  while (str[i] && (ftt_isalnum(str[i]) || str[i] == '_'))
    i++;
  if (str[i] != 0)
  {
    shell->g_status = 1;
    return ((void)printf("minishell: unset: '%s': not a valid identifier\n",str), NULL);
  }
  return (str);
}

void  unset_args(char *str)
{
  if (get_key(str) == NULL)
    return ;
  if(ft_lstdel_env(&shell->env_list, str))
  {
      printf("minishell: unset: '%s': not a valid identifier\n",str);
       shell->g_status = 1;
       return ;
  }
  shell->g_status = 0;
}

void  unset_cmd(char **args)
{
  int i;

  i = 1;
  while (args[i])
  {
    unset_args(args[i]);
    i++;
  }
}
