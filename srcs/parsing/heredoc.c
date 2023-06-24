/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:09:27 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/24 20:57:21 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_doc_sigint(int signal)
{
	(void)signal;
	exit(1);
}

void	ft_doc(void)
{
	int		expander;
	t_mini	*mini;
	t_token	*token;

	mini = g_shell->mini;
	expander = 0;
	while (mini)
	{
		token = mini->token;
		while (token)
		{
			if (token->type == DOC)
			{
				if (ft_strchr(token->file, '\'') || ft_strchr(token->file,
						'\"'))
					expander = 1;
				token->file = remove_quotes(token->file);
				mini->in = her_doc(token->file, expander);
				mini->doc = mini->token->index;
			}
			token = token->next;
		}
		mini = mini->next;
	}
}

int	ft_herdoc(int tab[2], char *line, char *lim, int expander)
{
	if (!ft_strcmp(lim, line))
	{
		free(line);
		return (0);
	}
	if (!expander && ft_strchr(line, '$'))
		line = ft_fix_env(line);
	ft_putstr_fd(line, tab[1]);
	ft_putstr_fd("\n", tab[1]);
	free(line);
	return (1);
}

int	her_doc(char *lim, int expander)
{
	int		tab[2];
	char	*line;
	pid_t	fid;

	pipe(tab);
	fid = fork();
	line = NULL;
	signal(SIGINT, SIG_IGN);
	if (fid == 0)
	{
		signal(SIGINT, handle_doc_sigint);
		signal(SIGQUIT, SIG_IGN);
		while (1)
		{
			line = readline(">");
			if (line == NULL)
				exit(0);
			if (!ft_herdoc(tab, line, lim, expander))
				break ;
		}
		exit(0);
	}
	ft_finish_herdoc(line, tab);
	return (tab[0]);
}

int	ft_file_error(t_mini *tmp)
{
	if (tmp->out < 0)
	{
		g_shell->g_status = 1;
		tmp->out = -1;
	}
	if (tmp->in < 0)
	{
		g_shell->g_status = 1;
		tmp->out = -1;
	}
	if (errno == 21)
		tmp->out = -4;
	else if (errno == 13)
		tmp->out = -2;
	if (tmp->in < 0 || tmp->out < 0)
		return (1);
	return (0);
}
