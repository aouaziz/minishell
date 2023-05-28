/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 01:29:11 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 22:58:55 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t len)
{
	size_t	i;
	size_t	f;

	f = 0;
	i = 0;
	if (!s && !len)
		return (0);
	if (!find[f])
		return ((char *)s);
	while (s[i] && i < len)
	{
		f = 0;
		if (s[i] == find[f])
		{
			while (s[i + f] == find[f] && find[f] && (f + i) < len)
			{
				f++;
				if (!find[f])
					return ((char *)&s[i]);
			}
		}
		i++;
	}
	return (0);
}
