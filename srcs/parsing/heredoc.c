/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:09:27 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/14 03:17:56 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	handle_doc_sigint(int signal)
// {
	// (void)signal;
	// exit(1);
// }

// int	ft_doc(t_mini *file)
// {
	// t_space	line;
// 
//	signal(SIGINT, handle_doc_sigint);
	// line.i = open("/tmp/minishell", O_CREAT | O_RDWR | O_TRUNC, 0644);
	// if (line.i < 0)
	// {
		// perror("minishell");
		// return (0);
	// }
	// if (ft_strchr(file->token_list->file, '$') && (!ft_strchr(file->token_list->file, '\'') || !ft_strchr(file->token_list->file, '"')))
		// line.output_len = 1;
	// file->token_list->file = remove_quotes(file->token_list->file);
	// while (1)
	// {
		// line.input = readline("heredoc> ");
		// if (ft_strncmp(line.input, file->token_list->file, ft_strlen(doc)))
			// break ;
		// if (line.output_len)
			// line.input = ft_fix_env(line.input);
		// write(line.i, line.input, ft_strlen(line.input));
		// write(line.i, "\n", 1);
		// free(line.input);
	// }
	// free(line.input);
	// return (line.i);
// }

int	ft_fill_fds(t_mini *tmp)
{
	t_token	*curr;

	curr = tmp->token_list;
	tmp->in = 0;
	tmp->out = 1;
	//ft_doc(tmp);
	while (curr)
	{
		if (curr->type == IN)
			tmp->in = open(curr->file, O_RDONLY);
		else if (curr->type == OUT)
			tmp->out = open(curr->file, O_CREAT | O_RDONLY | O_TRUNC, 0644);
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

	//if(tmp->out == 1 && )
	//	tmp->out = -20;
	return (0);
}