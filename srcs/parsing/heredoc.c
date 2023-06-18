/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:09:27 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/18 09:48:38 by aouaziz          ###   ########.fr       */
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
	int expander;
	t_mini	*mini;
	
	mini = shell->mini;
	expander = 0;
	while (mini)
	{
		while (mini->token_list)
		{
			if (mini->token_list->type == DOC)
			{
				if (ft_strchr(mini->token_list->file , '\'') || ft_strchr(mini->token_list->file , '\"'))
					expander = 1;
				mini->token_list->file = remove_quotes(mini->token_list->file);
				mini->in = her_doc(mini->token_list->file, expander);
				mini->doc = mini->token_list->index;
			}
			mini->token_list = mini->token_list->next;
		}
		mini = mini->next;
	}
}

int	her_doc(char *lim, int expander)
{
	int		tab[2];
	char	*line;
	pid_t	fid;
	
	pipe(tab);
	fid = fork();
	if (fid == 0)
	{
		signal(SIGINT, handle_doc_sigint);
		signal(SIGQUIT, handle_doc_sigint);
		while (1)
		{
			line = readline(">");
			if (!ft_strncmp(lim, line, ft_strlen(line)))
			{
				free(line);
				break ;
			}
			if (expander == 0)
				line = ft_fix_env(line);
			ft_putstr_fd(line,tab[1]);
			ft_putstr_fd("\n",tab[1]);
			free(line);
		}
		exit(0);
	}
	wait(0);
	close(tab[1]);
	return (tab[0]);
}
void	ft_open_fd(t_mini *tmp, t_token *curr)
{
	int file;
	file = tmp->in;
	if (curr->type == IN)
	{
		tmp->in = open(curr->file, O_RDONLY);
		if(tmp->doc < curr->index && file > 0 && tmp->in > 0)
			tmp->in = file;
	}
	else if (curr->type == OUT)
		tmp->out = open(curr->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (curr->type == APD)
		tmp->out = open(curr->file, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (tmp->out < 0 || tmp->in < 0)
	{
		shell->g_status = 1;
		tmp->out = -1;
	}
}
int is_empty()
{
	t_mini *curr;
	curr = shell->mini;
	while (curr)
	{
		while (curr->token_list)
		{
			if(curr->token_list->type == DOC)
				return (1);
			curr->token_list = curr->token_list->next;
		}
		curr = curr->next;
	}
	return (0);
}
int	ft_fill_fds(void)
{
	t_token *curr;
	t_mini *tmp;
	
	tmp = shell->mini;
	while (tmp)
	{
		curr = tmp->token_list;
		tmp->in = 0;
		tmp->out = 1;
		while (curr)
		{
			ft_open_fd(tmp, curr);
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