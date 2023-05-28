/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:20:23 by aouaziz           #+#    #+#             */
/*   Updated: 2023/05/28 04:56:58 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	skip_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

int	check_brackets(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ((str[count] == '<' || str[count] == '>') && (str[count + 1] == ' '
				|| str[count + 1] == '\t'))
		{
			count = skip_whitespace(str, count + 1);
			if (str[count] == '<' || str[count] == '>' || str[count] == '|')
			{
				printf("Error: bracket syntax error detected.\n");
				g_status = 258;
				return (1);
			}
		}
		count++;
	}
	return (0);
}

char	ft_riplice(char c, int a)
{
	if (a == 1)
	{
		if (c == '\"')
			c = '\0';
		else
			c = '\"';
	}
	else
	{
		if (c == '\'')
			c = '\0';
		else
			c = '\'';
	}
	return (c);
}

int	ft_check(char *line)
{
	if (!ft_strlen(line))
		return (1);
	else if (row_check(line))
		return (1);
	else if (check_brackets(line))
		return (1);
	else if (check_quotes(line))
		return (1);
	else if (check_pipe(line))
		return (1);
	else if (ft_strlen(line) == 1)
	{
		g_status = 127;
		return (1);
	}
	return (0);
}

int	check_pipe(char *str)
{
	int	count;
	int	pipe_found;

	count = 0;
	pipe_found = 0;
	while (str[count])
	{
		if (str[count] == '|')
		{
			if (!pipe_found)
				pipe_found = 1;
			else if (pipe_found)
			{
				printf("Error: pipe syntax error detected.\n");
				g_status = 258;
				return (1);
			}
		}
		else
			pipe_found = 0;
		count++;
	}
	return (0);
}
