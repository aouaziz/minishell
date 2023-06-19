/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:17:27 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/19 06:25:47 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	pwd_cmd(void)
{
	char	tmp[1000];

	if (getcwd(tmp, sizeof(tmp)) == NULL)
		perror("error :");
	else
	{
		ftt_print_fd(1, tmp);
		ftt_print_fd(1, "\n");
	}
	g_shell->g_status = 0;
}
