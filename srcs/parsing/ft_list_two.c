/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:25:55 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/17 10:36:01 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_miniadd_back(t_mini **list, t_mini *new)
{
	t_mini	*i;

	if (!new)
		return ;
	i = ft_mini_lst_last(*list);
	if (!i)
		*list = new;
	else
		i->next = new;
}

t_mini	*ft_mini_lst_last(t_mini *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_token	*ft_token_lst_last(t_token *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_list	*add_cmd_to_list(t_list *cmd_list, char *cmd)
{
	t_list	*new;

	if (!cmd)
		return (NULL);
	new = ft_lstnew(cmd);
	if (!new)
		return (NULL);
	ft_lstadd_back(&cmd_list, new);
	return (cmd_list);
}

t_env	*ft_env_lstlast(t_env *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
