/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:24:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/05/28 04:39:12 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_lexer(char *cmd, char **env)
{
	int		i;
	char	**cmds;
	t_mini	*shell;
	t_env	*env_list;

	i = 0;
	shell = NULL;
	env_list = NULL;
	cmd = ft_replace_c_with_s_in_quotes(cmd, '|', (char)156);
	cmd = ft_replace_c_with_s_in_quotes(cmd, ' ', (char)155);
	cmd = add_spaces(cmd);
	cmds = ft_split(cmd, '|');
	env_list = fill_env_list(env_list, env);
	while (cmds[i])
	{
		cmds[i] = ft_replace_c_with_s_in_quotes(cmds[i], (char)156, '|');
		i++;
	}
	ft_add_to_the_lst(cmds, shell, env_list);
	return (cmds);
}

void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		//rl_replace_line("",0);
		rl_redisplay();
	}
	else
		return ;
}

int	main(int ac, char *av[], char **env)
{
	char	*line;
	char	**cmds;
	int		i;

	(void)av;
	i = 0;
	if (ac != 1)
	{
		printf("wrong argument");
		return (0);
	}
	while (1)
	{
		line = readline("Minishell$ ");
		if (!line)
		{
			printf("exit\n");
			exit(0);
		}
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigint);
		add_history(line);
		if (!ft_check(line))
			cmds = ft_lexer(line, env);
	}
}
