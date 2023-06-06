/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:37:15 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/05 10:45:02 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_name(char *line, t_space *l)
{
	l->i++;
	l->output_len = l->i;
	l->input_len = 0;
	if (line[l->i] == '?' && ft_strlen(line) == 2)
		return (ft_itoa(shell->g_status));
	while (ft_isalnum(line[l->output_len]))
	{
		l->input_len++;
		l->output_len++;
	}
	l->output = malloc(sizeof(char) * (l->input_len + 1));
	if (!l->output)
		return (NULL);
	l->output[l->input_len] = '\0';
	ft_strncpy(l->output, line + l->i, l->input_len);
	l->output = get_value(l->output);
	l->i = l->output_len - 1;
	return (l->output);
}

void	env_fix_c(char *line, t_space *l)
{
	static int	in_quotes;

	if (line[l->i] == '\'' || line[l->i] == '\"')
	{
		if (!in_quotes)
		{
			in_quotes = 1;
			l->c = line[l->i];
		}
		else if (in_quotes && line[l->i] == l->c)
			in_quotes = 0;
	}
}

char	*str_fill_up(char *line, t_space *l, char *c)
{
	char	*tmp;

	tmp = malloc(2);
	tmp[0] = line[l->i];
	tmp[1] = '\0';
	c = ft_strjoin(c, tmp);
	free(tmp);
	l->i++;
	return (c);
}

char	*get_value(char *name)
{
	char	*unprintable;
	t_env	*env;

	env = shell->env_list;
	if (*name > '1' && *name <= '9')
	{
		name++;
		return (name);
	}
	while (env)
	{
		if (!ft_strcmp(env->env_name, name))
		{
			free(name);
			return (env->env_value);
		}
		env = env->next;
	}
	free(name);
	unprintable = malloc(2);
	unprintable[0] = '\x7F';
	unprintable[1] = '\0';
	return (unprintable);
}

char	*ft_fix_env(char *line)
{
	t_space	l;

	l.input = malloc(1);
	l.input[0] = '\0';
	l.i = -1;
	while (line[++l.i])
	{
		env_fix_c(line, &l);
		if (line[l.i] == '$' && line[l.i + 1] == '$')
		{
			l.input = ft_charjoin(l.input, line[l.i]);
			l.i = l.i + 2;
		}
		if (line[l.i] == '$' && l.c != '\'')
		{
			l.output = get_name(line, &l);
			l.input = ft_strjoin(l.input, l.output);
		}
		else
			l.input = ft_charjoin(l.input, line[l.i]);
	}
	free(line);
	return (l.input);
}
