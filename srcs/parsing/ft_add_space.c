/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:54:53 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/22 18:03:32 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_check_operator(t_space *s, char *input)
{
	if (input[s->i] == '<' && input[(s->i) + 1] == '<')
		s->c = '<';
	else if (input[s->i] == '>' && input[s->i + 1] == '>')
		s->c = '>';
	if (s->i - 1 > 0 && input[s->i - 1] != ' ')
		s->output[s->output_len++] = ' ';
	s->output[s->output_len++] = s->c;
	s->output[s->output_len++] = s->c;
	s->output[s->output_len++] = ' ';
	if (input[s->i + 2] == ' ')
		s->i++;
	s->i += 2;
}

void	ft_check_operator_two(t_space *s, char *input)
{
	if (s->i - 1 > 0 && input[s->i - 1] != ' ')
		s->output[s->output_len++] = ' ';
	s->output[s->output_len++] = input[s->i];
	s->output[s->output_len++] = ' ';
	if (input[s->i + 1] == ' ')
		s->i++;
	s->i++;
}

char	*add_spaces(char *input)
{
	char	*operators;

	operators = "<>|";
	g_shell->l.c = '\0';
	g_shell->l.output = ft_malloc(sizeof(char *) * ft_strlen(input) + 1);
	g_shell->l.input_len = ft_strlen(input);
	g_shell->l.output_len = 0;
	g_shell->l.i = 0;
	while (g_shell->l.i < g_shell->l.input_len)
	{
		if ((input[g_shell->l.i] == '>' && input[g_shell->l.i + 1] == '>')
			|| (input[g_shell->l.i] == '<' && input[(g_shell->l.i) + 1] == '<'))
			ft_check_operator(&g_shell->l, input);
		else if (ft_strchr(operators, input[g_shell->l.i]))
			ft_check_operator_two(&g_shell->l, input);
		else
		{
			g_shell->l.output[g_shell->l.output_len++] = input[g_shell->l.i];
			g_shell->l.i++;
		}
	}
	free(input);
	g_shell->l.output[g_shell->l.output_len] = '\0';
	return (g_shell->l.output);
}

void	remove_quotes_two(t_space *l, char c, int i)
{
	if (i == 1)
	{
		l->input_len = i;
		l->c = c;
	}
	else
	{
		l->input_len = i;
		l->c = '\0';
	}
}

char	*remove_quotes(char *str)
{
	t_space	l;

	l.input_len = 0;
	l.c = '\0';
	l.i = -1;
	l.output_len = 0;
	if (!str)
		return (NULL);
	l.output = ft_malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!l.output)
		return (NULL);
	while (str[++l.i])
	{
		if ((str[l.i] == '"' || str[l.i] == '\'') && !l.input_len)
			remove_quotes_two(&l, str[l.i], 1);
		else if (str[l.i] == l.c && l.input_len)
			remove_quotes_two(&l, str[l.i], 0);
		else
			l.output[l.output_len++] = str[l.i];
	}
	free(str);
	l.output[l.output_len] = '\0';
	return (l.output);
}
