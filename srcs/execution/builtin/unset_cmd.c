/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:53 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/17 23:57:18 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *get_key(char *str)
{
  if ((str[0] && !ftt_isalpha(str[0])) && ( str[0] && str[0] != '_'))
  {
    shell->g_status = 1;
    return ((void)printf("minishell: unset: `%s': not a valid identifier\n",str), NULL);
  }
  return (str);
}

void  unset_args(char *str)
{
  char *tmp;
  tmp = get_key(str);
  if (tmp == NULL)
    return ;
  if(ft_lstdel_env(&shell->env_list, str))
  {
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
