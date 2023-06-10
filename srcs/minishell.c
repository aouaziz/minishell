/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:24:00 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/10 15:08:21 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_lexer(char *cmd)
{
	int		i;
	char	**cmds;

	i = 0;
	shell->mini = NULL;
	cmd = ft_replace_c_with_s_in_quotes(cmd, '|', (char)156);
	cmd = ft_replace_c_with_s_in_quotes(cmd, ' ', (char)155);
	cmd = add_spaces(cmd);
	cmds = ft_split(cmd, '|');
	while (cmds[i])
	{
		cmds[i] = ft_replace_c_with_s_in_quotes(cmds[i], (char)156, '|');
		i++;
	}
	ft_add_to_the_lst(cmds, shell->mini);
	free(cmd);
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

	(void)av;
	shell = malloc(sizeof(t_shell));
	shell->env = env;
	shell->env_list = fill_env_list(shell->env, shell->env_list);
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
			ft_lexer(line);
	}
}
