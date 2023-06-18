/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:57:47 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/18 06:04:49 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_token(t_token *token_list)
{
	t_token	*current;
	t_token	*next;

	current = token_list;
	while (current != NULL)
	{
		next = current->next;
		free(current->file);    // Free the infile
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
		if (*(char *)(current->content) == c && ft_strlen(current->content) > 1)
			ft_strlcpy(current->content,current->content + 1,ft_strlen(current->content));
		else if (*(char *)(current->content) == c)
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
		curr->content  = ft_replace_c_with_s(curr->content, (char)157, '>');
		curr->content  = ft_replace_c_with_s(curr->content, (char)158, '<');
		tmp->cmds[i] = curr->content;
		i++;
		curr = curr->next;
	}
}