/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:09:27 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/22 21:55:59 by aouaziz          ###   ########.fr       */
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

	mini = g_shell->mini;
	expander = 0;
	while (mini)
	{
		while (mini->token)
		{
			if (mini->token->type == DOC)
			{
				if (ft_strchr(mini->token->file, '\'')
					|| ft_strchr(mini->token->file, '\"'))
					expander = 1;
				mini->token->file = remove_quotes(mini->token->file);
				mini->in = her_doc(mini->token->file, expander);
				mini->doc = mini->token->index;
			}
			mini->token = mini->token->next;
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
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, handle_doc_sigint);
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

void	ft_open_fd(t_mini *tmp, t_token *curr)
{
	int	file;

	file = tmp->in;
	if (curr->type == IN)
	{
		tmp->in = open(curr->file, O_RDONLY);
		if (tmp->doc < curr->index && file > 0 && tmp->in > 0)
			tmp->in = file;
	}
	else if (curr->type == OUT)
		tmp->out = open(curr->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (curr->type == APD)
		tmp->out = open(curr->file, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (tmp->out < 0 || tmp->in < 0)
	{
		g_shell->g_status = 1;
		tmp->out = -1;
	}
	else
		g_shell->g_status = 0;
}
