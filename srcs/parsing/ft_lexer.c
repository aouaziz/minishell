/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:23 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/20 16:21:16 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_add_to_the_lst(char **cmd)
{
	int		i;
	t_mini	*tmp;
	char	**cmds;

	i = 0;
	while (cmd[i])
	{
		cmds = ft_split(cmd[i], ' ');
		cmds = ft_fix_c_in_qoutes(cmds);
		tmp = ft_minilstnew(cmds);
		if (tmp == NULL)
			return ;
		ft_miniadd_back(&g_shell->mini, tmp);
		i++;
	}
	fill_index();
	ft_fill_fds();
	if (is_empty())
		ft_doc();
	g_shell->size = ft_lstsize_s(g_shell->mini);
	if (g_shell->size == 1 && !g_shell->mini->cmd_list)
		return ;
	//ft_mini_list_print(g_shell->mini);
	executing();
	free_double_env(cmds);
}

void	fill_index(void)
{
	int		i;
	t_mini	*tmp;
	t_token	*tok;

	i = 0;
	tmp = g_shell->mini;
	tok = g_shell->mini->token;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	i = 1;
	while (tok)
	{
		tok->index = i;
		i++;
		tok = tok->next;
	}
}

char	**ft_fix_c_in_qoutes(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		cmds[i] = ft_replace_c_with_s_in_quotes(cmds[i], (char)155, ' ');
		if ((i > 0 && ft_strncmp(cmds[i - 1], "<<", 2)) || cmds[1] == NULL)
		{
			if(ft_strchr(cmds[i], '$'))
				cmds[i] = ft_fix_env(cmds[i]);
			cmds[i] = remove_quotes(cmds[i]);
		}
		i++;
	}
	return (cmds);
}

char	*ft_replace_c_with_s(char *line, char c, char s)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			line[i] = s;
		i++;
	}
	return (line);
}

char	*ft_replace_c_with_s_in_quotes(char *line, char c, char s)
{
	int		in_quotes;
	char	quote_char;
	int		i;

	in_quotes = 0;
	quote_char = '\0';
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '"')
		{
			if (!in_quotes)
			{
				in_quotes = 1;
				quote_char = line[i];
			}
			else if (in_quotes && line[i] == quote_char)
				in_quotes = 0;
		}
		else if (line[i] == c && in_quotes)
			line[i] = s;
		i++;
	}
	return (line);
}
