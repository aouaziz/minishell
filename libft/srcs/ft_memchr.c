/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 21:16:43 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 23:00:04 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*d;

	i = 0;
	a = (unsigned char)c;
	d = (unsigned char *)s;
	while (n > i)
	{
		if (d[i] == a)
			return (&d[i]);
		i++;
	}
	return (0);
}
