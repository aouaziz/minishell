/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:14 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:14 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int builtin_fork_status(char **str)
{
    if (!str)
        return (-1);
    if (!ftt_strcmp("cd", str[0]))
        return(1);
   if (!ftt_strcmp("pwd", str[0]))
        return(0);
    if (!ftt_strcmp("echo", str[0]))
        return(0);
   /* if (!ftt_strcmp("exit", str[0]))
        return(1);*/
    if (!ftt_strcmp("env", str[0]))
        return(0);
    if (!ftt_strcmp("unset", str[0]))
        return(1);
    if (!ftt_strcmp("export", str[0]))
    {
        if (!str[1])
            return (0);
        return(1);
    }
    return (-1);
}

void    execute_builtin(t_mini *mini, char **dupli, int status)
{
    char **str;

    str = shell->env;
    if (status == 2)
        str = dupli;
    if (!ftt_strcmp("cd", shell->mini->cmds[0]))
        shell->env = cd_cmd(shell->mini->cmds, str);
   else if (!ftt_strcmp("pwd", shell->mini->cmds[0]))
        pwd_cmd(str, mini->cmds);
    else if (!ftt_strcmp("echo", shell->mini->cmds[0]))
        echo_cmd(mini->cmds);
    else if (!ftt_strcmp("exit", shell->mini->cmds[0]))
        exit_cmd(mini->cmds);
    else if (!ftt_strcmp("env", shell->mini->cmds[0]))
        env_cmd(str, mini->cmds);
    else if (!ftt_strcmp("unset", shell->mini->cmds[0]))
        shell->env = unset_cmd(str, mini->cmds);
    else if (!ftt_strcmp("export", shell->mini->cmds[0]))
        shell->env = export_cmd(str, mini->cmds);
}