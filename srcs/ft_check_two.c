/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:06:40 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/04 13:25:01 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	row_check(char *str)
{
	int	len;

	str = ft_strtrim(str, " ");
	str = ft_strtrim(str, "\t");
	len = ft_strlen(str);
	if (str[0] == '|' || str[len - 1] == '|')
	{
		printf("Error: pipe syntax error detected.\n");
		g_status = 258;
		return (1);
	}
	else if (str[len - 1] == '>' || str[len - 1] == '<')
	{
		printf("Error: bracket syntax error detected.\n");
		g_status = 258;
		return (1);
	}
	return (0);
}

int	check_quotes(char *str)
{
	t_space	l;

	l.i = -1;
	l.output_len = 0;
	l.input_len = 0;
	while (str[++l.i])
	{
		if (str[l.i] == '\"' && l.c != '\'')
		{
			l.c = ft_riplice(l.c, 1);
			l.input_len++;
		}
		else if (str[l.i] == '\'' && l.c != '\"')
		{
			l.c = ft_riplice(l.c, 0);
			l.output_len++;
		}
	}
	if (l.output_len % 2 != 0 || l.input_len % 2 != 0)
	{
		printf("Error: unclosed quotes detected .\n ");
		g_status = 258;
		return (1);
	}
	return (0);
}

void	ft_lst_fix(t_mini *lst)
{
	lst->cmd_list = NULL;
	lst->cmds = NULL;
	lst->token_list = NULL;
	lst->next = NULL;
}
void	ft_free_lst(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}
void	ft_free_mini(t_mini **mini)
{
	t_mini	*tmp;

	while (*mini)
	{
		tmp = (*mini)->next;
		ft_free((*mini)->cmds);
		ft_free_token((*mini)->token_list);
		ft_free_lst((*mini)->cmd_list);
		free(*mini);
		(*mini) = tmp;
	}
}

// void	ft_free_env(t_env **head)
// {
// 	t_env	*current;
// 	t_env	*next;

// 	current = *head;
// 	next = NULL;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		free(current->env_name);  // Free env_name
// 		free(current->env_value); // Free env_value
// 		free(current);            // Free the current element
// 		current = next;
// 	}
// 	*head = NULL;
// }
