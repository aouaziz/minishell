/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 08:17:27 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/21 17:23:33 by mel-garr         ###   ########.fr       */
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
