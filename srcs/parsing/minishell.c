/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:24:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/23 03:54:29 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_lexer(char *cmd)
{
	int		i;
	char	**cmds;

	i = 0;
	cmd = ft_replace_c_with_s_in_quotes(cmd, '|', (char)156);
	cmd = ft_replace_c_with_s_in_quotes(cmd, ' ', (char)155);
	cmd = ft_replace_c_with_s_in_quotes(cmd, '>', (char)157);
	cmd = ft_replace_c_with_s_in_quotes(cmd, '<', (char)158);
	cmd = add_spaces(cmd);
	cmds = ft_split(cmd, '|');
	while (cmds[i])
	{
		cmds[i] = ft_replace_c_with_s_in_quotes(cmds[i], (char)156, '|');
		i++;
	}
	ft_add_to_the_lst(cmds);
	free_double_env(cmds);
	ft_free_mini();
	free(cmd);
}

void	ft_start(char **env)
{
	g_shell = malloc(sizeof(t_shell));
	g_shell->env = ftt_strdup_2(env);
	g_shell->env_list = fill_env_list(g_shell->env, g_shell->env_list);
	g_shell->free = NULL;
	g_shell->mini = NULL;
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int ac, char *av[], char **env)
{
	char	*line;

	(void)av;
	ft_start(env);
	if (ac != 1)
	{
		printf("wrong argument");
		return (0);
	}
	while (1)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		line = readline("minishell$ ");
		if (!line)
		{
			printf("exit\n");
			exit(0);
		}
		add_history(line);
		if (!ft_check(line))
			ft_lexer(line);
	}
}
