/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:23 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/15 15:40:27 by mel-garr         ###   ########.fr       */
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
		ft_miniadd_back(&shell->mini, tmp);
		i++;
	}
	fill_index();
	if (ft_fill_fds())
		return ;
	shell->size = ft_lstsize_s(shell->mini);
	//print_env_list(shell->env_list,shell->env);
	//ft_mini_list_print(shell->mini);
	executing();
}

void fill_index(void)
{
	int i;
	t_mini *tmp;
	t_token *tok;
	
	i = 0;
	tmp = shell->mini;
	tok = shell->mini->token_list;
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
		if (i > 0 && ft_strcmp(cmds[i - 1], "<<"))
		{
			cmds[i] = ft_fix_env(cmds[i]);
			cmds[i] = remove_quotes(cmds[i]);
		}
		i++;
	}
	return (cmds);
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

void	remove_quotes_two(t_space *l, char c, int i)
{
	if (i == 1)
	{
		l->input_len = i;
		l->c = c;
	}
	else
	{
		l->input_len = i;
		l->c = '\0';
	}
}

char	*remove_quotes(char *str)
{
	t_space	l;

	l.input_len = 0;
	l.c = '\0';
	l.i = -1;
	l.output_len = 0;
	if (!str)
		return (NULL);
	l.output = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!l.output)
		return (NULL);
	while (str[++l.i])
	{
		if ((str[l.i] == '"' || str[l.i] == '\'') && !l.input_len)
			remove_quotes_two(&l, str[l.i], 1);
		else if (str[l.i] == l.c && l.input_len)
			remove_quotes_two(&l, str[l.i], 0);
		else
			l.output[l.output_len++] = str[l.i];
	}
	free(str);
	l.output[l.output_len] = '\0';
	return (l.output);
}
