/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:08 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/19 06:25:47 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	fti_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	get_flag(char *str)
{
	int	j;

	j = 0;
	if (fti_strlen(str) < 2)
		return (0);
	if (str[j] != '-' || str[1] != 'n')
		return (0);
	j++;
	while (str[j])
	{
		if (str[j] != 'n')
			return (0);
		j++;
	}
	if (str[j] == 0)
		return (1);
	return (1);
}

void	echo_cmd(char **str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (str[i] && get_flag(str[i]))
	{
		flag = 1;
		i++;
	}
	while (str[i])
	{
		ftt_print_fd(1, str[i]);
		if (str[i + 1])
			ftt_print_fd(1, " ");
		i++;
	}
	if (flag == 0)
		ftt_print_fd(1, "\n");
	g_shell->g_status = 0;
}
