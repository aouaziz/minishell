/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/06/09 07:57:23 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:23 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_free_solo_mini(void)
{
	ft_free(g_shell->mini->cmds);
	ft_free_token(g_shell->mini->token);
	ft_free_lst(g_shell->mini->cmd_list);
	free(g_shell->mini);
}

void	free_pipes(t_exe *exe)
{
	int	i;

	i = 0;
	if (exe->size > 1)
	{
		while (i < exe->size - 1)
		{
			free(exe->tube[i]);
			i++;
		}
		if (exe->size > 1)
			free(exe->tube);
	}
}

void	init_strcut(t_exe *exe)
{
	int	i;

	i = 0;
	exe->size = ft_lstsize_s(g_shell->mini);
	if (exe->size > 1)
	{
		exe->tube = (int **)malloc(sizeof(int *) * (exe->size - 1));
		if (!exe->tube)
			return (ftt_print_fd(2, "can't allocate pipes\n"), exit(1));
		while (i < exe->size - 1)
		{
			exe->tube[i] = (int *)malloc(sizeof(int) * 2);
			if (!exe->tube[i])
				return (ftt_print_fd(2, "pipes\n"), exit(1));
			i++;
		}
		i = 0;
		while (i < exe->size - 1)
		{
			if (pipe(exe->tube[i]) == -1)
				return (ftt_print_fd(2, "pipe pb\n"), exit(1));
			i++;
		}
	}
}

void	executing(void)
{
	t_exe	*exe;
	pid_t	fid;
	int		j;

	exe = malloc(sizeof(t_exe));
	exe->path = ftt_strdup("");
	init_strcut(exe);
	fid = pipe_and_fork(exe);
	if (fid == -1)
		ftt_print_fd(2, "minishell :fork :Resource temporarily unavailable\n");
	close_pipes(exe);
	waitpid(fid, &j, 0);
	while (wait(NULL) != -1)
		;
	if (fid != -1 && fid != 0)
	{
		g_shell->g_status = WEXITSTATUS(j);
		if (WIFSIGNALED(j))
			g_shell->g_status = WTERMSIG(j) + 128;
	}
	free_pipes(exe);
	free(exe->path);
	free(exe);
}
