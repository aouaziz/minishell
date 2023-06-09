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

#include "../../includes/minishell.h"

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
    if (!ftt_strcmp("exit", str[0]))
        return(1);
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

void    execute_builtin(t_shell *shell, char **str, int i)
{
    if (!ftt_strcmp("cd", str[0]))
        shell->env = cd_cmd(str, shell->env);
   else if (!ftt_strcmp("pwd", str[0]))
        pwd_cmd(shell->env, str);
    else if (!ftt_strcmp("echo", str[0]))
        echo_cmd(str);
    else if (!ftt_strcmp("exit", str[0]))
        exit_cmd(str, i);
    else if (!ftt_strcmp("env", str[0]))
        env_cmd(env,str);
    else if (!ftt_strcmp("unset", str[0]))
        shell->env = unset_cmd(shell->env, str);
    else if (!ftt_strcmp("export", str[0]))
        shell->env = export_cmd(shell->env, str);
}