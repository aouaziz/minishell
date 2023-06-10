/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_execution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:23 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:23 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void    free_pipes(t_exe *exe)
{
    int i;

    i = 0;
    while (i < exe->size)
		free(exe->tube[i++]);
	if (exe->size > 1)
		free(exe->tube);
}

void    init_strcut(t_shell *shell, t_exe *exe)
{
    int i;

    i = 0;
    exe->size = ft_lstsize_s(shell);

    if (exe->size > 1)
    {
        exe->tube = (int **)malloc(sizeof(int *) * (exe->size - 1));
        if (!exe->tube)
            return (ftt_print_fd(2, "can't allocate pipes\n"), exit (1));
        i = 0;
        while (i < exe->size)
        {
            exe->tube[i] =(int *) malloc(sizeof(int) * 2);
            if (!exe->tube[i])
            return (ftt_print_fd(2, "can't allocate each pipe\n"), exit(1));
            i++;
        }
        i = 0;
        while (i < exe->size)
        {
            if (pipe(exe->tube[i]) == -1)
                return (ftt_print_fd(2, "pipe pb\n"),exit (1));
            i++;
        }
    }
}

void    executing(t_shell *shell)
{
    t_exe exe;
    pid_t fid;
    int j;

    init_strcut(shell, &exe);
    fid = pipe_and_fork(shell, &exe);
    if (fid == -1)
        ftt_print_fd(2, "can't fork\n");
    if (var->pid == -1)
		ft_putstr2("fork", "Resource temporarily unavailable\n", 3);
	close_pipes(exe);
	waitpid(fid, &j, 0);
	while (wait(NULL) != -1)
		;
	if (fid != -1 && fid != 0)
	{
		shell->g_staus = WEXITSTATUS(j);
		if (WIFSIGNALED(j))
		    shell->g_staus = WTERMSIG(j) + 128;
	}
	free_pipes(exe);
}