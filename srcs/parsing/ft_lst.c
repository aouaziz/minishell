/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:19:30 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/18 05:25:57 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_mini	*ft_minilstnew(char **str)
{
	t_mini	*new;
	t_space l;
	
	new = malloc(sizeof(t_mini));
	if (!new)
		return (NULL);
	l.i = 0;
	ft_lst_fix(new);
	while (str[l.i])
	{
		if (!ft_strncmp(str[l.i], ">>",2))
			new->token_list = add_token_to_list(new->token_list, APD, str[++l.i]);
		else if (ft_strncmp(str[l.i], ">",1) == 0)
			new->token_list = add_token_to_list(new->token_list, OUT, str[++l.i]);
		else if (ft_strncmp(str[l.i], "<",1) == 0)
			new->token_list = add_token_to_list(new->token_list, IN, str[++l.i]);
		else if (ft_strncmp(str[l.i], "<<",2) == 0)
			new->token_list = add_token_to_list(new->token_list, DOC, str[++l.i]);
		else
			new->cmd_list = add_cmd_to_list(new->cmd_list, str[l.i]);
		l.i++;
	}
	ft_fill_cmds(new);
	return (new);
}

t_token	*add_token_to_list(t_token *token_list, int type, char *content)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->file = content;
	new->next = NULL;
	ft_token_list_add_back(&token_list, new);
	return (token_list);
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

void	ft_mini_list_print(t_mini *lst)
{
	while (lst)
	{
		printf("Index:%d\n",lst->index);
		printf("CMDs:\n");
		for (int i = 0; lst->cmds[i] != NULL; i++)
			printf("  %d: %s\n", i, lst->cmds[i]);
		printf("Tokens:\n");
		for (t_token *token = lst->token_list; token != NULL; token = token->next)
		{
			printf("Token Type: %d\n", token->type);
			printf("Input File: %s\n", token->file);
			printf("file index: %d\n",lst->token_list->index);
		}
		printf("fd:\n");
		printf("in:\t %d\n", lst->in);
		printf("out: \t%d\n", lst->out);
		printf("next | \n");
		lst = lst->next;
	}
}
