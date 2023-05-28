/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:59 by aouaziz           #+#    #+#             */
/*   Updated: 2023/05/18 10:20:40 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	s = ft_strlen(src);
	if (!dst && !dstsize)
		return (s);
	d = ft_strlen(dst);
	if (!dstsize)
		return (s);
	if (d > dstsize)
		return (s + dstsize);
	while (src[i] && i + d < dstsize - 1)
	{
		dst[i + d] = src[i];
		i++;
	}
	dst[d + i] = 0;
	return (s + d);
}
