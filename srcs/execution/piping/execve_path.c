/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:57:20 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:57:20 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void    ftt_print_12(char *str, int type)
{
    ftt_print_fd(2, "minishell: ");
    ftt_print_fd(2, str);
    if (type == 3)
    {
    ftt_print_fd(2, "is a directory\n");
        exit(126);
    }
    if (type == 1)
    ftt_print_fd(2, "command not found\n");
    if (type == 2)
    ftt_print_fd(2, "Permission denied\n");
    if (type == 4)
    ftt_print_fd(2, "No such file or directory\n");
    exit(127);
}

char *solide_path(t_mini *mini, t_exe *exe)
{
    char **splited_path;
    int i;
    char *path;

    i = 0;
    splited_path = split_path(mini);
    if(!splited_path)
        return(ftt_print_12(mini, 5), NULL);
    while (splited_path && splited_path[i])
    {
        path = ftt_strjoin(splited_path[i], "/");
        path = ftt_strjoin(path , mini->cmds[0]);
        if (access(path, F_OK & X_OK) == 0)
            return (do_free(splited_path), path);
        free(path);
        i++;
    }
    return (do_free(splited_path), ftt_print_12(mini->cmds[0], 1), NULL);
}

int pathern(t_exe *exe, t_mini *mini)
{
    DIR *dir;
    if (mini->cmds[0] && mini->cmds[0][0] == '\0')
        return (ftt_print_12(mini->cmds[0], 1), NULL);
    if (!mini->env)
        return (ftt_print_12(mini->cmds[0], 2), NULL);
    if (ftt_search(mini->cmds[0], '/') == 0)
    {
        dir = opendir(mini->cmds[0]);
        if (dir)
            return (free(dir), ftt_print_12(mini->cmds[0], 3), NULL);
        if (access(mini->cmds[0], F_OK & X_OK) == 0)
            return(mini->cmds[0]);
        else
            return(ftt_print_12(mini->cmds[0], 4), NULL);
    }
    return (solide_path(mini, exe));
}