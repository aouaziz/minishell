/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:11 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/22 18:16:24 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	change_dir(char *path)
{
	char	ret[1000];

	getcwd(ret, 1000);
	ft_env_change_value("OLDPWD", ret);
	if (chdir(path) != 0)
		return (ftt_print_fd(2, "cd: no such file or directory:"),
			ftt_print_fd(2, path), ftt_print_fd(2, "\n"));
	getcwd(ret, 1000);
	ft_env_change_value("PWD", ret);
}

void	cd_cmd(char **args)
{
	char	*path;

	path = NULL;
	if (!args[1] || !ftt_strncmp(args[1], "--", 3))
	{
		path = ft_get_value("HOME");
		if (!path)
			return (ftt_print_fd(2, "HOME not set\n"));
		return (change_dir(path));
	}
	else if (ftt_strncmp(args[1], "-", 2) == 0)
	{
		path = ft_get_value("OLDPWD");
		if (!path)
			return (ftt_print_fd(2, "OLDPWD not set\n"));
		return (change_dir(path));
	}
	else
		return (change_dir(args[1]));
}
