/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:58:38 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 07:58:39 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

char	*ftt_strrchr(char *s, int c)
{
	size_t	slen;
	char	*a;

	a = (char *)s;
	slen = ftt_strlen(s);
	while (slen > 0 && a[slen] != (char)c)
		slen--;
	if (a[slen] == (char)c)
		return (a + slen);
	return (0);
}