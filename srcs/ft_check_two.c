/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:06:40 by aouaziz           #+#    #+#             */
/*   Updated: 2023/05/28 04:51:35 by aouaziz          ###   ########.fr       */
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

void	ft_fill_cmds(t_mini *tmp)
{
	int		count;
	int		i;
	t_list	*curr;

	ft_lstdel(&tmp->cmd_list, '\x7F');
	count = ft_lstsize(tmp->cmd_list);
	i = 0;
	tmp->cmds = malloc(sizeof(char *) * (count + 1));
	if (tmp->cmds == NULL)
		return ;
	tmp->cmds[count] = NULL;
	curr = tmp->cmd_list;
	while (curr)
	{
		tmp->cmds[i] = curr->content;
		i++;
		curr = curr->next;
	}
}

void	ft_lst_fix(t_mini *lst)
{
	lst->cmd_list = NULL;
	lst->cmds = NULL;
	lst->token_list = NULL;
	lst->next = NULL;
}
