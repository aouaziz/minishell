/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 19:49:42 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/22 18:15:23 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

long	check_validity(char *str)
{
	int		i;
	long	ret;
	int		signe;

	signe = 1;
	ret = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		ret = (ret * 10) + str[i] - 48;
		i++;
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != 0)
		return (-1);
	return (ret * signe);
}

void	do_one_arg(int ret, char *str)
{
	if (ret >= 0)
		g_shell->g_status = ft_atoi(str);
	else
	{
		ftt_print_fd(2, "minishell: exit: ");
		ftt_print_fd(2, str);
		ftt_print_fd(2, ": numeric argument required\n");
		g_shell->g_status = 255;
	}
	exit(g_shell->g_status);
}

void	do_the_rest(int ret1, int ret2, char *s1)
{
	if ((ret1 >= 0 && ret2 >= 0) || (ret1 >= 0 && ret2 < 0))
	{
		g_shell->g_status = 1;
		return (ftt_print_fd(2, "minishell: exit: too many arguments\n"));
	}
	else
	{
		g_shell->g_status = 255;
		ftt_print_fd(2, "minishell: exit: ");
		ftt_print_fd(2, s1);
		ftt_print_fd(2, ": numeric argument required\n");
		exit(g_shell->g_status);
	}
}

void	exit_cmd(char **str)
{
	int		p_exit;
	long	ret1;
	long	ret2;

	p_exit = 0;
	if (g_shell->size == 1)
		ftt_print_fd(2, "exit\n");
	if (!str[1])
		exit(g_shell->g_status);
	if (str[1])
		ret1 = check_validity(str[1]);
	if (str[1] && str[2])
		ret2 = check_validity(str[2]);
	if (str[1] && !str[2])
		do_one_arg(ret1, str[1]);
	if (str[1] && str[2])
		do_the_rest(ret1, ret2, str[1]);
}
