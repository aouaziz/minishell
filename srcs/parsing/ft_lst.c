/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:19:30 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/24 07:05:08 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_mini	*ft_minilstnew(char **str)
{
	t_mini	*new;
	t_space	l;

	new = ft_malloc(sizeof(t_mini));
	if (!new)
		return (NULL);
	l.i = 0;
	ft_lst_fix(new);
	while (str[l.i])
	{
		if (!ft_strncmp(str[l.i], ">>", 2))
			new->token = add_token_to_list(new->token, APD, str[++l.i]);
		else if (ft_strncmp(str[l.i], ">", 1) == 0)
			new->token = add_token_to_list(new->token, OUT, str[++l.i]);
		else if (ft_strncmp(str[l.i], "<<", 2) == 0)
			new->token = add_token_to_list(new->token, DOC, str[++l.i]);
		else if (ft_strncmp(str[l.i], "<", 1) == 0)
			new->token = add_token_to_list(new->token, IN, str[++l.i]);
		else
			new->cmd_list = add_cmd_to_list(new->cmd_list, str[l.i]);
		l.i++;
	}
	ft_fill_cmds(new);
	return (new);
}

t_token	*add_token_to_list(t_token *token, int type, char *content)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->file = content;
	new->next = NULL;
	ft_token_list_add_back(&token, new);
	return (token);
}

void	ft_token_list_add_back(t_token **lst, t_token *new)
{
	t_token	*i;

	if (!new)
		return ;
	i = ft_token_lst_last(*lst);
	if (!i)
		*lst = new;
	else
		i->next = new;
}
