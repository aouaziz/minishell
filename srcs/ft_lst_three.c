/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:57:47 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/05 09:17:20 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_token(t_token *token_list)
{
	t_token	*current;
	t_token	*next;

	current = token_list;
	while (current != NULL)
	{
		next = current->next;
		free(current->infile);    // Free the infile
		free(current->outfile);   // Free the outfile
		free(current->delimiter); // Free the delimiter
		free(current);            // Free the node
		current = next;
	}
}

void	ft_lstdel(t_list **list, char c)
{
	t_list	*current;
	t_list	*previous;
	t_list	*tmp;

	current = *list;
	previous = NULL;
	while (current != NULL)
	{
		if (*(char *)(current->content) == c)
		{
			tmp = current;
			if (previous != NULL)
				previous->next = current->next;
			else
				*list = current->next;
			current = current->next;
			free(tmp->content);
			free(tmp);
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
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

void	ft_free_env(t_env **head)
{
	t_env	*current;
	t_env	*next;

	current = *head;
	next = NULL;
	while (current != NULL)
	{
		next = current->next;
		free(current->env_name);  // Free env_name
		free(current->env_value); // Free env_value
		free(current);            // Free the current element
		current = next;
	}
	*head = NULL;
}

int	ft_fill_fds(t_mini *tmp)
{
	t_token	*curr;

	curr = tmp->token_list;
	while (curr)
	{
		if (curr->type == IN)
			tmp->in = open(curr->infile, O_RDONLY, 0644);
		else if (curr->type == OUT)
			tmp->out = open(curr->outfile, O_CREAT | O_RDONLY | O_TRUNC, 0777);
		//else if (curr->type == DOC)
		//	ft_doc(curr->delimiter);
		else if (curr->type == APD)
			tmp->out = open(curr->outfile, O_CREAT | O_RDWR | O_APPEND | 0644);
		if (tmp->out < 0 || tmp->in < 0)
		{
			printf(" No such file or directory\n");
			g_status = 1;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}
