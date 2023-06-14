/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:56:01 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/14 06:29:37 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../../includes/minishell.h"

void	fill_env_list_add(char *cmd)
{
	int		i;
	char	*name;
	char	*value;
	t_env	*tmp;

	i = 0;
    if(!cmd)
        return;
	name = ft_get_env_name(cmd);
	value = ft_get_env_value(cmd);
	if (!name || !value)
	{
		free(name);
		free(value);
		return;
	}
	tmp = ft_env_lst_new(name, value);
	ft_env_lstadd_back(&shell->env_list, tmp);
	i++;
}

char **ft_env_list_to_env(void)
{
    t_env *tmp; 
	int env_size;
	char **env;
	int i ;
    
    i = 0;
    tmp = shell->env_list;
    env_size = ft_lst_env_size(tmp);
    env = malloc((env_size + 1) * sizeof(char *));
	if (!env)
		return NULL;
	env[env_size] == NULL;
	while (tmp)
	{
		env_size = (ft_strlen(tmp->env_name) + ft_strlen(tmp->env_value) + 2);
		env[i]= malloc(sizeof(char) * env_size);
		env[i]= ft_strncpy(env[i],tmp->env_name,ft_strlen(tmp->env_name));
        env[i]= ft_charjoin(env[i],'=');
        env[i]= ft_strjoin(env[i],tmp->env_value);
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;  
	
	return (env);
}

int ft_lst_env_size(t_env *lst)
{
	int count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return count;
}

void	ft_lstdel_env(t_env **list, char *cmd)
{
	t_env	*current;
	t_env	*previous;
	char *name;
	t_env	*tmp;

	current = *list;
	name = ft_get_env_name(cmd);
    printf("%s\n",name);
	previous = NULL;
	while (current != NULL)
	{
		if (!ft_strcmp(current->env_name , name))
		{
			tmp = current;
			if (previous != NULL)
				previous->next = current->next;
			else
				*list = current->next;
			current = current->next;
			free(tmp->env_name);
			free(tmp->env_value);
		    free(tmp);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
}