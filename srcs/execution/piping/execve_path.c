/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/06/09 07:57:20 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:20 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	do_free(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

char	**split_path(char **env)
{
	char	**new_str;
	char	*big_path;
	int		i;

	i = 0;
	new_str = NULL;
	big_path = get_content_env(env, "PATH=");
	return (ft_split((char const *)big_path, ':'));
}

void	ftt_print_12(char *str, int type)
{
	ftt_print_fd(2, "minishell: ");
	ftt_print_fd(2, str);
	if (type == 3)
	{
		ftt_print_fd(2, " is a directory\n");
		exit(126);
	}
	if (type == 1)
		ftt_print_fd(2, " command not found\n");
	if (type == 2)
		ftt_print_fd(2, " Permission denied\n");
	if (type == 4)
		ftt_print_fd(2, " No such file or directory\n");
	exit(127);
}

int	solide_path(t_mini *mini, t_exe *exe)
{
	char	**splited_path;
	int		i;

	i = 0;
	splited_path = split_path(ft_env_list_to_env());
	if (!splited_path)
		return (ftt_print_12(mini->cmds[0], 4), 0);
	while (splited_path && splited_path[i])
	{
		exe->path = ftt_strjoin(splited_path[i], "/");
		exe->path = ftt_strjoin(exe->path, mini->cmds[0]);
		if (access(exe->path, F_OK & X_OK) == 0)
			return (do_free(splited_path), 1);
		free(exe->path);
		i++;
	}
	return (do_free(splited_path), ftt_print_12(mini->cmds[0], 1), 0);
}

int	pathern(t_exe *exe, t_mini *mini)
{
	DIR	*dir;

	if (mini->cmds[0] && mini->cmds[0][0] == '\0')
		return (ftt_print_12(mini->cmds[0], 1), 0);
	if (!g_shell->env_list)
		return (ftt_print_12(mini->cmds[0], 2), 0);
	if (ftt_search(mini->cmds[0], '/') == 0)
	{
		dir = opendir(mini->cmds[0]);
		if (dir)
			return (free(dir), ftt_print_12(mini->cmds[0], 3), 0);
		if (access(mini->cmds[0], F_OK & X_OK) == 0)
			return (exe->path = mini->cmds[0], 1);
		else
			return (ftt_print_12(mini->cmds[0], 4), 0);
	}
	return (solide_path(mini, exe));
}
