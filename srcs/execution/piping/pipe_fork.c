/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:26 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:26 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void close_pipes(t_exe *exe)
{
    int i;

    i = 0;
    while (i < exe->size - 1)
    {
        close (exe->tube[i][0]);
        close (exe->tube[i][1]);
        i++;
    }
}

void    check_error_file(t_mini *mini)
{
    if (mini->out == -3)
    {
        ftt_print_fd(2, "minishell: ambigious redirect\n");
        exit(1);
    }
    if (mini->in == -1 || mini->out == -1)
    {
        ftt_print_fd(2, "minishell: No such file or directory\n");
        exit (1);
    }
}

void    do_pipe_path(t_mini *mini, t_exe *exe, int status)
{
    check_error_file(mini);
    if (status && !pathern(exe , mini))
        exit(1);
    if (exe->size == 1)
    {
        if (mini->in >= 0)
            dup2(mini->in, 0);
        if (mini->out >= 0)
            dup2(mini->out, 1);
    }
    else
    {
        if (mini->in >= 0)
            dup2(mini->in , 0);
        else if (mini->in < 0 && mini->index > 0)
            dup2(exe->tube[mini->index - 1][0], 0);
        if (mini->out >= 0)
            dup2(mini->out, 1);
        else if (mini->out < 0 && mini->index < exe->size - 1)
            dup2(exe->tube[mini->index][1], 1);
        close_pipes(exe);
    }
}

void    proc_from_in_to_out(t_mini *mini, t_exe *exe)
{

    if (builtin_fork_status(mini->cmds) != -1)
    {
        do_pipe_path(mini, exe, 0);
        execute_builtin(mini);
        exit(0);
    }
    else
    {
        do_pipe_path(mini, exe, 1);
        execve(exe->path, mini->cmds, ft_env_list_to_env());
        perror("error");
        exit(1);
    }
}

void	cat_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		//rl_replace_line("",1);
	//	rl_redisplay();
	}
}

pid_t   pipe_and_fork(t_exe *exe)
{
    pid_t fid;
    int i;
   
    i = 0;
    signal(SIGINT, cat_handle_sigint);
    signal(SIGQUIT, cat_handle_sigint);
   if (exe->size == 1 && builtin_fork_status(shell->mini->cmds) != -1)
       return (execute_builtin(shell->mini), 0);
    else
    {
        while (i < exe->size)
        {
            fid = fork();
            if (fid == 0)
            {
                proc_from_in_to_out(shell->mini, exe);
                exit(0);
            }
            shell->mini = shell->mini->next;
            i++;
        }
    }
    return (fid);
}