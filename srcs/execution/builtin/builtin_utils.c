/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/06/09 07:57:14 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:14 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	builtin_fork_status(char **str)
{
	if (!str)
		return (-1);
	if (!ftt_strcmp("cd", str[0]))
		return (1);
	if (!ftt_strcmp("pwd", str[0]))
		return (0);
	if (!ftt_strcmp("echo", str[0]))
		return (0);
	if (!ftt_strcmp("exit", str[0]))
		return (1);
	if (!ftt_strcmp("env", str[0]))
		return (0);
	if (!ftt_strcmp("unset", str[0]))
		return (1);
	if (!ftt_strcmp("export", str[0]))
	{
		if (!str[1])
			return (0);
		return (1);
	}
	return (-1);
}

int	check_one(t_mini *mini)
{
	if (mini->out == -3 || mini->in == -3)
	{
		ftt_print_fd(2, "minishell: ambigious redirect\n");
		return (1);
	}
	if (mini->in == -1 || mini->out == -1)
	{
		ftt_print_fd(2, "minishell: No such file or directory\n");
		return (1);
	}
	if (mini->out == -2)
	{
		ftt_print_fd(2, "minishell: Permission denied\n");
		return (1);
	}
	else if (mini->out == -4)
	{
		ftt_print_fd(2, "minishell: is a directory\n");
		return (1);
	}
	return (0);
}

void	dup_one(int fdin, int fdout, int status, t_mini *mini)
{
	if (g_shell->size == 1 && status == 1)
	{
		if (mini->in >= 0)
			dup2(mini->in, 0);
		if (mini->out >= 0)
			dup2(mini->out, 1);
	}
	else if (g_shell->size == 1 && status == 2)
	{
		if (g_shell->size == 1)
		{
			dup2(fdin, 0);
			dup2(fdout, 1);
		}
	}
}

void	execute_builtin(t_mini *mini)
{
	int	fdin;
	int	fdout;

	fdin = dup(0);
	fdout = dup(1);
	if (check_one(mini))
		return ;
	dup_one(fdin, fdout, 1, mini);
	if (!ftt_strcmp("cd", g_shell->mini->cmds[0]))
		cd_cmd(g_shell->mini->cmds);
	else if (!ftt_strcmp("pwd", g_shell->mini->cmds[0]))
		pwd_cmd();
	else if (!ftt_strcmp("echo", g_shell->mini->cmds[0]))
		echo_cmd(mini->cmds);
	else if (!ftt_strcmp("exit", g_shell->mini->cmds[0]))
		exit_cmd(mini->cmds);
	else if (!ftt_strcmp("env", g_shell->mini->cmds[0]))
		env_cmd(mini->cmds);
	else if (!ftt_strcmp("unset", g_shell->mini->cmds[0]))
		unset_cmd(mini->cmds);
	else if (!ftt_strcmp("export", g_shell->mini->cmds[0]))
		export_cmd(mini->cmds);
	dup_one(fdin, fdout, 2, mini);
}
