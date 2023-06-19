/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:29:30 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/19 00:47:37 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char *ft_get_va_lue(char *str)
{
  int i;

  i = 0;
  while(str[i] && str[i] != '=' && str[i] != '+')
        i++;
  if (!str[i])
    return (ftt_strdup(""));
  if (str[i] == '+' && str[i + 1] == '=')
    i = i + 2;
  else if (str[i] == '=')
    i++;
  return (ft_substr(str, i, ftt_strlen(str) - i + 1));
}

char *ft_get_name(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] != '=' && str[i] != '+')
        i++;
    return (ftt_substr(str, 0, i));
}

void	fill_env_list_add_back(char *name, char *value)
{
	t_env	*tmp;
	
  tmp = ft_env_lst_new(name, value);
	ft_env_lstadd_back(&g_shell->env_list, tmp);
}

int ft_exist(char *str)
{
  t_env *tmp;

  tmp = g_shell->env_list;
  while (tmp)
  {
    if (ft_strcmp(tmp->env_name, str) == 0)
      return (1);
    tmp = tmp->next;
  }
  return (2);
}

void  change_status_export(int status, char *name)
{
  t_env *tmp;
  tmp = g_shell->env_list;
  while (tmp)
  {
    if (ft_strcmp(name, tmp->env_name) == 0)
      {
        tmp->status = status;
        break;
      }
      tmp = tmp->next;
  }
  
}

void  do_status(int exist, int l, char *str)
{
  if (exist == 2 && l == 1)
    return (change_status_export(-1, str));
  return (change_status_export(0, str));
}

void    export_element(char *str, int l)
{
    char *name;
    char *value;
    int exist;

    name = ft_get_name(str);
    value = ft_get_va_lue(str);
    exist = ft_exist(name);
    if (exist == 2)
    fill_env_list_add_back(name, value);
    else if (exist == 1 && l == 1)
      return ;
    else if (exist == 1 && l == 3)
      value = ftt_strjoin(ft_get_value(name),value);
    ft_env_change_value(name, value);
    do_status(exist, l, name);
}

int valid_arg(char *str)
{
    int i;

    i = 0;
    if ((str[0] && str[0] != '_') && (str[0] && !ftt_isalpha(str[0])))
        return (-1);
    while (str[i] && ftt_isalnum(str[i]))
        i++;
    if (str[i] == 0)
        return (1);
    else if (str[i] == '=')
        return (2);
    else if (str[i] == '+' && str[i + 1] == '=')
        return (3);
    return (-1);    
}

void    export_env(char **args)
{
    int i;
    int l;

    i = 1;
    while (args[i])
    {
        l = valid_arg(args[i]);
        if (l > -1)
            export_element(args[i], l);
        else
            printf ("minishell: export: `%s': not a valid identifier \n", args[i]);
        i++;
    }
}

void	ppprint_env_list(void)
{
    t_env *tmp;
    
    tmp = g_shell->env_list;
    while (tmp)
    {
      if (tmp->status == 0)
        printf("declare -x %s=\"%s\" \n", tmp->env_name, tmp->env_value);
      else if (tmp->status == -1)
        printf ("declare -x %s\n", tmp->env_name);
      tmp = tmp->next;
    }
}

void  env_export_cmd(void)
{
  t_env *tmp;
  t_env *n_head;
  char *tmp_name;
  char *tmp_value;
    
  tmp = g_shell->env_list;
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
  pid_t fid;
  
  if (!args[1])
  {
    fid = fork();
    if (fid == 0)
    {
      env_export_cmd();
      exit(0);
    }
    else
      wait(0);
    return;
  }
  else
    export_env(args);
}
