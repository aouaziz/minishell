/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:57:47 by aouaziz           #+#    #+#             */
/*   Updated: 2023/05/28 02:50:59 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	ft_free(t_list **a)
// {
// 	t_list	*tmp;

// 	while (*a)
// 	{
// 		tmp = (*a)->next;
// 		free(*a);
// 		(*a) = tmp;
// 	}
// }

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
