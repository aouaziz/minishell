/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:19:54 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/24 21:01:28 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_array(char **array)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	if (array == NULL)
		return (0);
	while (array[i] != NULL)
	{
		length++;
		i++;
	}
	return (length);
}
