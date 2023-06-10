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
        if (mini->in > 0)
            dup2(mini->in , 0);
        else if (mini->in < 0 && mini->index > 0)
            dup2(exe->tube[mini->index - 1][0], 0);
        if (mini->out > 0)
            dup2(mini->out, 1);
        else if (mini->out && mini->index < exe->size - 1)
            dup2(exe->tube[mini->index][1], 1);
    }
    close_pipes(exe);
}

void    proc_from_in_to_out(t_mini *mini, t_exe *exe, char **env)
{
    if (builtin_fork_status(mini->cmds) != -1)
    {
        do_pipe_path(mini, exe, 0);
        execute_builtin(mini->cmds, env, 2);
        exit(0);
    }
    else
    {
        do_pipe_path(mini, exe, 1);
        execve(exe->path, mini->cmds, env);
        perror("error");
        exit(1);
    }
}

pid_t   pipe_and_fork(t_shell *shell, t_exe *exe)
{
    pid_t fid;
    int i;
    char **dupli;

    dupli = ftt_strdup_2(shell->env);
    i = 0;
    if (exe->size == 1 && !builtin_fork_status(shell->mini->cmds))
        return (execute_builtin(shell , shell->mini, dupli, 1), 0);
    while (i < exe->size)
    {
        fid = fork;
        if (fid == 0)
        {
            proc_from_in_to_out(shell->mini, exe, dupli);
        }
        shell->mini = shell->mini->next;
        i++;
    }
    reutn (fid);
}