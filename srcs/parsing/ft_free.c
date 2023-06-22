/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 13:23:52 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/22 18:03:41 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lstadd_back_free(t_free **lst, t_free *new)
{
	t_free	*i;

	if (!new)
		return ;
	if (!lst || !*lst)
		i = NULL;
	else
		i = ft_lstlast_free(*lst);
	if (!i)
		*lst = new;
	else
		i->next = new;
}

t_free	*ft_lstlast_free(t_free *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->next)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
	return (NULL);
}

t_free	*ft_lstnew_free(void *content)
{
	t_free	*new;

	new = malloc(sizeof(t_free));
	if (!new)
		return (0);
	new->adres = (unsigned long)content;
	new->next = 0;
	return (new);
}

void	*ft_malloc(int size)
{
	void	*ptr;
	t_free	*new;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new = ft_lstnew_free(ptr);
	ft_lstadd_back_free(&g_shell->free, new);
	return (ptr);
}

void	ft_finish_herdoc(char *line, int *tab)
{
	wait(0);
	close(tab[1]);
	free(line);
}
