/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:09:27 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/11 14:32:45 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_doc_sigint(int signal)
{
	(void)signal;
	exit(1);
}

int	ft_doc(char *doc)
{
	t_space	line;

	//signal(SIGINT, handle_doc_sigint);
	line.i = open("/tmp/minishell", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (line.i < 0)
	{
		perror("minishell");
		return (0);
	}
	if (ft_strchr(doc, '$') && (!ft_strchr(doc, '\'') || !ft_strchr(doc, '"')))
		line.output_len = 1;
	doc = remove_quotes(doc);
	while (1)
	{
		line.input = readline("heredoc> ");
		if (ft_strncmp(line.input, doc, ft_strlen(doc)))
			break ;
		if (line.output_len)
			line.input = ft_fix_env(line.input);
		write(line.i, line.input, ft_strlen(line.input));
		write(line.i, "\n", 1);
		free(line.input);
	}
	free(line.input);
	return (line.i);
}

int	ft_fill_fds(t_mini *tmp)
{
	t_token	*curr;

	curr = tmp->token_list;
	tmp->in = 0;
	tmp->out = 1;
	while (curr)
	{
		if (curr->type == IN)
			tmp->in = open(curr->file, O_RDONLY);
		else if (curr->type == OUT)
			tmp->out = open(curr->file, O_CREAT | O_RDONLY | O_TRUNC, 0644);
		else if (curr->type == DOC)
			tmp->in = ft_doc(curr->file);
		else if (curr->type == APD)
			tmp->out = open(curr->file, O_CREAT | O_RDWR | O_APPEND | 0644);
		if (tmp->out < 0 || tmp->in < 0)
		{
			perror(curr->file);
			shell->g_status = 1;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}
