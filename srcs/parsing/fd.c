/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 00:31:22 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/23 22:26:22 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_fill_fds(void)
{
	t_token	*curr;
	t_mini	*tmp;

	tmp = g_shell->mini;
	while (tmp)
	{
		curr = tmp->token;
		tmp->out = 1;
		while (curr)
		{
			if(ft_open_fd(tmp, curr))
				break;
			curr = curr->next;
		}
		if (tmp->out == 1)
			tmp->out = -20;
		if (tmp->in == 0)
			tmp->in = -20;
		tmp = tmp->next;
	}
	return (0);
}

void	ft_cmd_not_found(void)
{
	printf("minishell: command not found.\n");
	g_shell->g_status = 127;
}

void	print_env_list(t_env *env_list, char **env)
{
	int	i;

	i = 0;
	while (env_list)
	{
		printf("\tenv: %s\n", env[i]);
		printf("env_name: %s\n", env_list->env_name);
		printf("env_value: %s\n", env_list->env_value);
		printf("next: %p\n", (void *)env_list->next);
		env_list = env_list->next;
		i++;
	}
}

static void	ft_free_env_list(t_env *tmp, t_env *current)
{
	current = current->next;
	free(tmp->env_name);
	free(tmp->env_value);
	free(tmp);
}

int	ft_lstdel_env(t_env **list, char *cmd)
{
	t_env	*current;
	t_env	*previous;
	t_env	*tmp;

	current = *list;
	previous = NULL;
	while (current != NULL)
	{
		if (!ft_strcmp(current->env_name, cmd))
		{
			tmp = current;
			if (previous != NULL)
				previous->next = current->next;
			else
				*list = current->next;
			ft_free_env_list(tmp, current);
			return (0);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	return (1);
}
