/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:24:19 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/04 15:10:27 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*i;

	if (!new)
		return ;
	i = ft_env_lstlast(*lst);
	if (!i)
		*lst = new;
	else
		i->next = new;
}

t_env	*ft_env_lst_new(void *content, void *content_value)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (0);
	new->env_name = content;
	new->env_value = content_value;
	new->next = NULL;
	return (new);
}

char	*ft_get_env_name(char *s)
{
	int		i;
	char	*env_name;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	env_name = malloc(sizeof(char *) * (i + 1));
	if (!env_name || !s[i])
		return (NULL);
	ft_strncpy(env_name, s, i);
	env_name[i] = '\0';
	return (env_name);
}

char	*ft_get_env_value(char *s)
{
	int		i;
	int		value_length;
	char	*value;

	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (!s[i])
		return (NULL);
	value_length = ft_strlen(s) - i;
	value = malloc((value_length + 1) * sizeof(char));
	if (!value)
		return (NULL);
	value[value_length] = '\0';
	ft_strncpy(value, s + i + 1, value_length);
	return (value);
}

void	fill_env_list(char **cmd)
{
	int		i;
	char	*name;
	char	*value;
	t_env	*tmp;
	env_list = NULL;

	i = 0;
	while (cmd[i])
	{
		name = ft_get_env_name(cmd[i]);
		value = ft_get_env_value(cmd[i]);
		if (!name || !value)
		{
			free(name);
			free(value);
			return ;
		}
		tmp = ft_env_lst_new(name, value);
		ft_env_lstadd_back(&env_list, tmp);
		i++;
	}
}

void	print_env_list(t_env *env_list, char **env)
{
	int	i;
	i = 0;
	(void) env;
	while (env_list)
	{
	//	printf("\tenv: %s\n", env[i]);
		printf("env_name: %s\n", env_list->env_name);
		printf("env_value: %s\n", env_list->env_value);
		printf("next: %p\n", (void *)env_list->next);
		env_list = env_list->next;
		i++;
	}
}
