/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:05 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/18 01:04:47 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pprint_env_list(void)
{
  t_env *tmp;

  tmp = shell->env_list;
  
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
    shell->g_status = 127;
    return ;
  }
  pprint_env_list();
  shell->g_status = 0;
}
// int main(int ac, char **av, char **env)
// {
//   env_cmd(env, av);
// }
