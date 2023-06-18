/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:09:27 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/18 06:03:47 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	handle_doc_sigint(int signal)
// {
	// (void)signal;
	// exit(1);
// }
// 
// int	ft_doc(t_mini *file)
// {
	// t_space	line;
// 
	// if (ft_strchr(file->token_list->file, '$')
		// && (!ft_strchr(file->token_list->file, '\'')
				// || !ft_strchr(file->token_list->file, '"')))
		// line.output_len = 1;
	// file->token_list->file = remove_quotes(file->token_list->file);
	// file->doc = her_doc(file->token_list->file, line.output_len);
	// return (line.i);
// }
// 
// int her_doc(char *lim, int expander)
// {
    // int tab[2];
    // char *line;
    // pid_t fid;
// 
    // pipe(tab);
    // fid = fork();
    // if (fid == 0)
    // {
		// signal(SIGINT, handle_doc_sigint);
        // while(1)
        // {
            // line = readline(">");
            // if (!ft_strncmp(lim, line , ft_strlen(line)))
            // {
                // free(line);
                // break ;
            // }
            // ftt_putstr_fd(tab[1], line);
            // free(line);
        // }
        // exit (0);
    // }
    // wait(0);
    // close(tab[1]);
    // return(tab[0]);
// }

int	ft_fill_fds(void)
{
	t_token *curr;
	t_mini *tmp;

	tmp = shell->mini;
	//ft_doc(tmp);
	while (tmp)
	{
		curr = tmp->token_list;
		tmp->in = 0;
		tmp->out = 1;
		while (curr)
		{
			if (curr->type == IN)
				tmp->in = open(curr->file, O_RDONLY);
			else if (curr->type == OUT)
				tmp->out = open(curr->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
			else if (curr->type == APD)
			{
				tmp->out = open(curr->file, O_CREAT | O_RDWR | O_APPEND , 0644);
				printf("out = %d\n", tmp->out);
			}
			if (tmp->out < 0 || tmp->in < 0)
			{
				shell->g_status = 1;
				tmp->out = -1;
			}
			curr = curr->next;
		}
		if (tmp->out == 1 )
			tmp->out = -20;
		if (tmp->in == 0 )
			tmp->in = -20;
		tmp = tmp->next;
	}
	return (0);
}