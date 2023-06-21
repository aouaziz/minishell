/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:06:40 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/21 10:35:48 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	row_check(char *str)
{
	int	len;
	char *tmp;
	tmp = ft_strtrim(str, "\t ");
	len = ft_strlen(str);
	if (tmp[0] == '|' || tmp[len - 1] == '|')
	{
		printf("minishell: pipe syntax error detected.\n");
		g_shell->g_status = 258;
		free(str);
		free(tmp);
		return (1);
	}
	else if (tmp[len - 1] == '>' || tmp[len - 1] == '<')
	{
		printf("minishell: bracket syntax error detected.\n");
		g_shell->g_status = 258;
		free(str);
		free(tmp);
		return (1);
	}
	free(tmp);
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
		printf("minishell: unclosed quotes detected .\n ");
		g_shell->g_status = 258;
		return (1);
	}
	return (0);
}

void	ft_lst_fix(t_mini *lst)
{
	lst->cmd_list = NULL;
	lst->cmds = NULL;
	lst->token = NULL;
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

void	ft_free_mini(void)
{
	t_mini	*next;
	

	while (g_shell->mini)
	{
		next = g_shell->mini->next;
		ft_free(g_shell->mini->cmds);
		ft_free_token(g_shell->mini->token);
		ft_free_lst(g_shell->mini->cmd_list);
		free(g_shell->mini);
		g_shell->mini= next;
	}
	g_shell->mini = NULL;
}
