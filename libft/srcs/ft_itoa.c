/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 05:16:39 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 23:00:07 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_intlen(int ln)
{
	int	len;

	len = 0;
	if (ln <= 0)
		len++;
	while (ln)
	{
		len++;
		ln /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nn;

	len = ft_intlen(n);
	nn = n;
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	s[len--] = '\0';
	if (nn < 0)
	{
		s[0] = '-';
		nn *= -1;
	}
	if (nn == 0)
		s[0] = '0';
	while (nn)
	{
		s[len--] = (nn % 10) + '0';
		nn /= 10;
	}
	return (s);
}
/*
 itoa = int to ascii;
 */
