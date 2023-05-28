/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:38:02 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 22:59:23 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;
	char	b;

	i = 0;
	a = (char *)s;
	b = (char)c;
	while (a[i])
	{
		if (a[i] == b)
			return (&a[i]);
		i++;
	}
	if (!b)
		return (&a[i]);
	return (0);
}
