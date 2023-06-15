/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:11 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/15 15:29:50 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void  hearchi(void)
{
  char *path;
  int i;

  path = NULL;
  path = getcwd(path, 1000);
  if (!path)
    return ;
  if (ftt_strncmp("/", path, 2) == 0)
    return ;
  i = ftt_strlen(path);
  while(path[i] != '/')
      i--;
  path = ftt_substr(path , 0, i);
  if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path));
  
  ft_env_change_value("OLDPWD", ft_get_value("PWD"));
  ft_env_change_value("PWD", path);
  free(path);
}


void  change_dir(char *path)
{
  char *ret;
  
  ret = NULL;
  if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path), ftt_print_fd(2, "\n"));
  ft_env_change_value("OLDPWD", ft_get_value("PWD"));
  ft_env_change_value("PWD", path);
  free(ret);
}

void  cd_cmd(char **args)
{
  char *path;

  path = NULL;  
   if (args[1] != NULL  && args[2] != NULL)
    return (ftt_print_fd(2, "bash: cd: too many arguments\n"));
  if (!args[1] || !ftt_strncmp(args[1], "--", 3))
  {
    path = ft_get_value("HOME");
    if(!path)
      return (ftt_print_fd(2, "HOME not set\n"));
    return (change_dir(path));
  }
  else if (ftt_strncmp(args[1], "-", 2) == 0)
  {
    path = ft_get_value("OLDPWD");
    if (!path)
      return (ftt_print_fd(2, "OLDPWD not set\n"));
    return (change_dir(path));
  }
  else if (ftt_strncmp(args[1], "..", 3) == 0)
    return (hearchi());
  else
    return(change_dir(args[1]));
}
