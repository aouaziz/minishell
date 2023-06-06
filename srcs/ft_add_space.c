/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_space.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:54:53 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/06 07:20:21 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_check_operator(t_space *s, char *input)
{
	if (input[s->i] == '<' && input[(s->i) + 1] == '<')
		s->c = '<';
	else if (input[s->i] == '>' && input[s->i + 1] == '>')
		s->c = '>';
	if (s->i -1 > 0 && input[s->i - 1] != ' ')
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
	t_space	s;
	char	*operators;

	operators = "<>|";
	s.c = '\0';
	s.output = malloc(sizeof(char *) * ft_strlen(input) + 1);
	s.input_len = ft_strlen(input);
	s.output_len = 0;
	s.i = 0;
	while (s.i < s.input_len)
	{
		if ((input[s.i] == '>' && input[s.i + 1] == '>') || (input[s.i] == '<'
				&& input[(s.i) + 1] == '<'))
			ft_check_operator(&s, input);
		else if (ft_strchr(operators, input[s.i]))
			ft_check_operator_two(&s, input);
		else
		{
			s.output[s.output_len++] = input[s.i];
			s.i++;
		}
	}
	free(input);
	s.output[s.output_len] = '\0';
	return (s.output);
}
