/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:56:59 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/17 07:23:40 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int check_element_validity(char *str)
{
  int i;

  i = 0;
  while (str[i] != '=' && str[i] != '+' && str[i])
    if (ftt_isalnum(str[i]) || str[i] == '_')
      i++;
  if (str[i] == '+' && str[i + 1] == '=')
    return (1);
  else if (str[i] == '=')
    return (2);
  shell->g_status = 1;
  return (-1);
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
void  export_cmd(char **args)
{
  int i;
  int l;
  
  i = 1;
  if (!args[1])
    env_cmd(args);
  while (args[i])
  {
    l = check_element_validity(args[i]);
    if (l > -1)
      export_element(args[i], l);
    else
      printf ("minishell: export: '%s': not a valid identifier \n", args[i]);
    i++;
  }
}