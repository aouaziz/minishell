/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_strjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:58:45 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/18 10:14:38 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	*ftt_memcpy(void *dst, void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!d && !s)
	{
		return (0);
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ftt_strjoin(char *s1, char *s2)
{
	char	*r;
	size_t	slen1;
	size_t	slen2;

	if (!s1 || !s2)
		return (0);
	slen1 = ftt_strlen(s1);
	slen2 = ftt_strlen(s2);
	r = malloc(slen1 + slen2 + 1);
	if (!r)
		return (0);
	if (r)
	{
		ftt_memcpy(r, s1, slen1 + 1);
		ftt_memcpy(r + slen1, s2, slen2 + 1);
	}
	return (r);
}

char	*ftt_charjoin(char *s1, char s2)
{
	char	*r;
	char	*c;
	size_t	slen1;

	if ((!s1) || (!s2))
		return (0);
	slen1 = ftt_strlen(s1);
	r = malloc(slen1 + 2);
	c = malloc(2);
	if (!r || !c)
		return (0);
	c[0] = s2;
	c[1] = '\0';
	if (r)
	{
		ftt_memcpy(r, s1, slen1 + 1);
		ftt_memcpy(r + slen1, c, 2);
	}
	return (r);
}
