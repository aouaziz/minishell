/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:05 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 07:41:51 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

int  env_cmd(char **env, char **args)
{
  if (args[1] != 0)
    return(ftt_print_fd(2, "not handled\n"), 2);
  if (!env)
    return(ftt_print_fd(2, "env not set\n"), 2);
  print_env(env);
  return (1);
}
// int main(int ac, char **av, char **env)
// {
//   env_cmd(env, av);
// }
