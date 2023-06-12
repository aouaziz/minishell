/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:11 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/12 08:13:12 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void  set_up_pwd_env(char **env, char *ret)
{
  change_content(env, get_indice_env(env, "OLDPWD="), "OLDPWD",get_content_env(env, "PWD"));
  change_content(env, get_indice_env(env, "PWD="), "PWD", ret);
  free(ret);
}

void  hearchi(char **env)
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
  set_up_pwd_env(env, path);
}


char  **change_dir(char **env, char *path)
{
  char *ret;
  
  ret = NULL;
  if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path), ftt_print_fd(2, "\n"), env);
  printf ("wsselt hnan\n");
  getcwd(ret , 1000);
  set_up_pwd_env(env, ret);
  return (env);
}

char **cd_cmd(char **args, char **env)
{
  char *path;

   if (args[1] != NULL  && args[2] != NULL)
    return (ftt_print_fd(2, "bash: cd: too many arguments\n"), env);
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
    return (hearchi(env), env);
  else
    return(change_dir(env, args[1]));
  return (env);
}

/*int main(int ac, char **av, char **env)
{
  char **str;
  int i = -1;
  while (env[++i])
  {
    printf("%s\n", env[i]);
  }
  char **avv;
  char **envv;
  avv = ftt_strdup_2(av);
  envv = ftt_strdup_2(env);
  
  str = cd_cmd(avv, envv);
  exit(1);
  i = -1;
  printf ("-----------------------------------\n");
  while (str[++i])
  {
    printf("%s\n", str[i]);
  }
}*/