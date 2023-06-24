/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:56:34 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/24 20:57:15 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_open_fd(t_mini *tmp, t_token *curr)
{
	int	file;

	file = tmp->in;
	if (ft_strchr(curr->file, (char)159))
	{
		if (curr->type == IN)
			tmp->in = -3;
		else
			tmp->out = -3;
		return (1);
	}
	if (curr->type == IN)
		tmp->in = open(curr->file, O_RDONLY);
	else if (curr->type == OUT)
		tmp->out = open(curr->file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (curr->type == APD)
		tmp->out = open(curr->file, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (ft_file_error(tmp))
		return (1);
	return (0);
}
