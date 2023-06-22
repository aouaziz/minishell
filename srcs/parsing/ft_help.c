/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 02:56:01 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/22 21:47:41 by aouaziz          ###   ########.fr       */
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
	if (!cmd)
		return ;
	name = ft_get_env_name(cmd);
	value = ft_get_env_value(cmd);
	if (!name || !value)
	{
		free(name);
		free(value);
		return ;
	}
	tmp = ft_env_lst_new(name, value);
	ft_env_lstadd_back(&g_shell->env_list, tmp);
	i++;
}

int	ft_env_change_value(char *name, char *value)
{
	t_env	*tmp;

	tmp = g_shell->env_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->env_name, name))
		{
			free(tmp->env_value);
			tmp->env_value = ft_strdup(value);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

char	**ft_env_list_to_env(void)
{
	t_env	*tmp;
	int		env_size;
	char	**env;
	int		i;

	i = 0;
	tmp = g_shell->env_list;
	env_size = ft_lst_env_size(tmp);
	env = malloc((env_size + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	env[env_size] = NULL;
	while (tmp)
	{
		env_size = (ft_strlen(tmp->env_name) + ft_strlen(tmp->env_value) + 2);
		env[i] = malloc(sizeof(char) * env_size);
		env[i] = ft_strncpy(env[i], tmp->env_name, ft_strlen(tmp->env_name));
		env[i] = ft_charjoin(env[i], '=');
		env[i] = ft_strjoin(env[i], tmp->env_value);
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	return (env);
}

int	ft_lst_env_size(t_env *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	*ft_get_value(char *name)
{
	t_env	*tmp;

	tmp = g_shell->env_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->env_name, name))
			return (tmp->env_value);
		tmp = tmp->next;
	}
	return (NULL);
}
