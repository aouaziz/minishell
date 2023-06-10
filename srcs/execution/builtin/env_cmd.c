/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:05 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 20:44:35 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void  env_cmd(char **env, char **args)
{
  if (args[1] != 0)
    return(ftt_print_fd(2, "not handled\n"));
  if (!env)
    return(ftt_print_fd(2, "env not set\n"));
  print_env(env);
}
// int main(int ac, char **av, char **env)
// {
//   env_cmd(env, av);
// }
