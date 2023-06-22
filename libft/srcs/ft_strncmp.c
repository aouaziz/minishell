/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:36:44 by aouaziz           #+#    #+#             */
/*   Updated: 2023/06/22 16:29:41 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s[i] != '\0' && d[i] != '\0' && s[i] == d[i] && i < n - 1)
		i++;
	return (s[i] - d[i]);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t			i;
	size_t			n;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	n = ft_strlen(s1);
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	if (n == 0 && ft_strlen(s2) == 0)
		return (0);
	while (s[i] != '\0' && d[i] != '\0' && s[i] == d[i])
		i++;
	return (s[i] - d[i]);
}
