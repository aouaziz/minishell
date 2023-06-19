/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:18:28 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/19 06:23:46 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	do_status(int exist, int l, char *str)
{
	if (exist == 2 && l == 1)
		return (change_status_export(-1, str));
	return (change_status_export(0, str));
}

void	cat_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int	valid_arg(char *str)
{
	int	i;

	i = 0;
	if ((str[0] && str[0] != '_') && (str[0] && !ftt_isalpha(str[0])))
		return (-1);
	while (str[i] && ftt_isalnum(str[i]))
		i++;
	if (str[i] == 0)
		return (1);
	else if (str[i] == '=')
		return (2);
	else if (str[i] == '+' && str[i + 1] == '=')
		return (3);
	return (-1);
}
