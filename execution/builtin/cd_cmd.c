#include "../mini.h"

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
    return (0);
  if (ftt_strncmp("/", path, 2) == 0)
    return (0);
  i = ftt_strlen(path);
  while(path[i] != '/')
      i--;
  path = ftt_substr(path , 0, i);
if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path), 1);
  set_up_pwd_env(env, path);
  return (0);
}


int  change_dir(char **env, char *path)
{
  char *ret;
  
  if (chdir(path) != 0)
    return(ftt_print_fd(2, "cd: no such file or directory:"), ftt_print_fd(2, path), 1);
  getcwd(ret , 1000);
  set_up_pwd_env(env, ret);
  return (0);
}

int  cd_cmd(char **env, char **args)
{
  char *path;
  
  if (args[2] != 0)
    return (ftt_print_fd(2, "bash: cd: too many arguments"), 2);
  if (!args[1] || !ftt_strncmp(args[1], "--", 3))
  {
    path = get_content_env(env, "HOME=");
    if(!path)
      return (ftt_print_fd(2, "HOME not set\n"), 1);
    return (change_dir(env, path));
  }
  else if (ftt_strncmp(args[1], "-", 2) == 0)
  {
    path = get_content_env(env, "OLDPWD");
    if (!path)
      return (ftt_print_fd(2, "OLDPWD not set\n"), 1);
    return (change_dir(env, path));
  }
  else if (ftt_strncmp(args[1], "--", 3) == 0)
    return (hearchi(env));
  else
    return(change_dir(env, args[1]));
  return (19);
}

int main(int ac, char **av, char **env)
{
  cd_cmd(env , av);
}