/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:31:14 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 22:59:20 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	slen;

	slen = ft_strlen(s1) + 1;
	s = malloc(slen * sizeof(char));
	if (!s)
		return (0);
	s = ft_memcpy(s, s1, slen);
	return (s);
}
