/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:05 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/19 00:47:37 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pprint_env_list(void)
{
  t_env *tmp;

  tmp = g_shell->env_list;
  
	while (tmp)
	{
    if(tmp->status == 0)
		  printf("%s=%s\n", tmp->env_name,tmp->env_value);
		tmp = tmp->next;
	}
}

void  env_cmd(char **args)
{
  if (args[1])
  {
    ftt_print_fd(2, "not handled\n");
    g_shell->g_status = 127;
    return ;
  }
  pprint_env_list();
  g_shell->g_status = 0;
}
// int main(int ac, char **av, char **env)
// {
//   env_cmd(env, av);
// }
