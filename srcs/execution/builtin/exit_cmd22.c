/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cmd22.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:02 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/22 18:14:49 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_ret_status(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str)
		return (1);
	if (str[0] == '-' || str[0] == '+')
		i++;
	j = i;
	if (str[i] == 0)
		return (16);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == j)
		return (16);
	if (str[i] != '\0')
		return (1);
	return (16);
}

void	exit_cmd(char **str)
{
	int	ret;

	ret = 0;
	if (str[1])
	{
		ret = get_ret_status(str[1]);
		if (ret == 16)
			return ((void)printf("minishell: exit: %s:numeric argument required\n", str[1]));
		if (ret == 1)
			g_shell->g_status = ft_atoi(str[1]);
	}
	if (g_shell->size == 1)
		printf("exit\n");
	if (!str[1])
		exit(g_shell->g_status);
	if (str[1] != NULL && str[2] != NULL && ret != 1)
	{
		printf("minishell: exit: too many arguments\n");
		g_shell->g_status = 1;
	}
	if (ret == 1)
		printf("minishell: exit: %s:numeric argument required\n", str[1]);
	if (str[2])
		return ;
	exit(g_shell->g_status);
}
