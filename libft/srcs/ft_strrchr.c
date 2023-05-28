/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:40:41 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 22:58:52 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;
	char	*a;

	a = (char *)s;
	slen = ft_strlen(s);
	while (slen > 0 && a[slen] != (char)c)
		slen--;
	if (a[slen] == (char)c)
		return (a + slen);
	return (0);
}
