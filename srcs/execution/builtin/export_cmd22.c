/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:59 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/17 23:22:45 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"



int check_element_validity(char *str)
{
  int i;

  i = 0;
  while (str[i] != '=' && str[i] != '+' && str[i])
  {
    if ((!ftt_isalpha(str[i]) && i == 0 ) && (str[i] != '_' && i == 0))
      return(-1);
    i++;
  }
  if (str[i] == '+' && str[i + 1] == '=')
    return (1);
  else if (str[i] == '=')
    return (2);
  else
    return (3);
  shell->g_status = 1;
}

char *gett_key(char *str)
{
  int i;

  i = 0;
  while (str[i] != '=' && str[i] != '+' && str[i])
    if (ftt_isalnum(str[i]) || str[i] == '_')
      i++;
  return (ftt_substr(str, 0, i));
}

int element_exist(char *str)
{
  t_env *tmp;

  tmp = shell ->env_list;
  while (tmp)
  {
    if (ft_strcmp(tmp->env_name, str) == 0)
      return (1);
    tmp = tmp->next; 
  }
  return (0);
}

char *jib_value(char *str)
{
  int i;
  int len;

  i = 0;
  len = ftt_strlen(str);
  while (str[i] != '=' && str[i] != '+' && str[i])
    if (ftt_isalnum(str[i]) || str[i] == '_')
      i++;
  if (str[i] == '+' && str[i + 1] == '=')
    i += 2;
  else if (str[i] == '=')
    i++;
  return (ftt_substr(str, i, len - i + 1));  
}

void  export_element(char *str, int status)
{
  int exist;
  char *name;
  char  *value;
  
  name = gett_key(str);
  printf ("---|%s|---\n", name);
  value = jib_value(str);
  exist = element_exist(name);
  if (exist == 0)
  {
    fill_env_list_add(str);
  }
  else if (exist == 1 && status == 2)
    ft_env_change_value(name, value);
  else if (exist == 1 && status == 3)
  {
    value = ftt_strjoin(ft_get_value(name) ,value);
   ft_env_change_value(name, value);
  }
  shell->g_status = 0;
}

void	ppprint_env_list(void)
{
  t_env *tmp;

  tmp = shell->env_list;
  
	while (tmp)
	{
    printf("declare -x %s=\"%s\"\n", tmp->env_name, tmp->env_value);
    tmp = tmp->next;
	}
}

void  env_export_cmd(t_env *env)
{
  t_env *tmp;
  t_env *n_head;
  char *tmp_name;
  char *tmp_value;
    
  tmp = env;
  while (tmp)
  {
    n_head = tmp->next;
    while (tmp && n_head)
    {
      if (ft_strcmp(tmp->env_name, n_head->env_name) > 0)
      {
        tmp_name = tmp->env_name;
        tmp_value = tmp->env_value;
        tmp->env_name = n_head->env_name;
        tmp->env_value = n_head->env_value;
        n_head->env_name = tmp_name;
        n_head->env_value = tmp_value;
      }
      n_head = n_head->next;
    }
    tmp = tmp->next;
  }
  ppprint_env_list();
}

void  export_cmd(char **args)
{
  int i;
  int l;
  t_env *tmp;
  pid_t fid;
  
  i = 1;
  fid = -1;
  tmp = shell->env_list;
  if (!args[1])
  {
    fid = fork();
    if (fid == 0)
    {
      env_export_cmd(tmp);
      exit(0);
    }
    else
      wait(0);
    return;
  }
    
  else
    while (args[i])
      {
        l = check_element_validity(args[i]);
          if (l > -1)
            export_element(args[i], l);
          else
            printf ("minishell: export: `%s': not a valid identifier \n", args[i]);
        i++;
      }
  if (fid == 0)
    printf ("tt\n");
}