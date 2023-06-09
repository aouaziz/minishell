/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:53 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 08:16:19 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int  unset_cmd(char **env, char **argv)
{
  int i;
  int index;
  
  i = 1;
  if (!argv[1])
    return (0);
  while (argv[i])
  {
    index = get_indice_env(env, argv[i]);
    if (index >= 0)
      unset_var_env(env, index);
    i++;
  }
  if (write(1, "\n", 1) == -1)
    return (-1);
  return (0);
}