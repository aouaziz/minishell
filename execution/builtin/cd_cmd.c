/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:11 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 08:06:03 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini.h"

void  set_up_pwd_env(char **env, char *ret)
{
  change_content(env, get_indice_env(env, "OLDPWD="), "OLDPWD",get_content_env(env, "PWD"));
  change_content(env, get_indice_env(env, "PWD="), "PWD", ret);
  free(ret);
}

int  hearchi(char **env)
{
  char *path;
  int i;

  path = getcwd(path, 1000);
  if (!path)
    return (env);
  if (ftt_strncmp("/", path, 2) == 0)
    return (env);
  i = ftt_strlen(path);
  while(path[i] != '/')
      i--;
  path = ftt_substr(path , 0, i);
if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path), env);
  set_up_pwd_env(env, path);
  return (env);
}


char  **change_dir(char **env, char *path)
{
  char *ret;
  
  if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path), 1);
  getcwd(ret , 1000);
  set_up_pwd_env(env, ret);
  return (env);
}

char  **cd_cmd(char **args, char **env)
{
  char *path;
  
  if (args[2] != 0)
    return (ftt_print_fd(2, "bash: cd: too many arguments"), env);
  if (!args[1] || !ftt_strncmp(args[1], "--", 3))
  {
    path = get_content_env(env, "HOME=");
    if(!path)
      return (ftt_print_fd(2, "HOME not set\n"), env);
    return (change_dir(env, path));
  }
  else if (ftt_strncmp(args[1], "-", 2) == 0)
  {
    path = get_content_env(env, "OLDPWD");
    if (!path)
      return (ftt_print_fd(2, "OLDPWD not set\n"), env);
    return (change_dir(env, path));
  }
  else if (ftt_strncmp(args[1], "--", 3) == 0)
    return (hearchi(env));
  else
    return(change_dir(env, args[1]));
  return (env);
}

int main(int ac, char **av, char **env)
{
  cd_cmd(env , av);
}