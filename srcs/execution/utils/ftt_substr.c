/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:58:57 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/18 10:15:07 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

size_t	ftt_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = ftt_strlen(src);
	if (dstsize)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (s);
}

char	*ftt_substr(char *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	slen;

	if (!s)
		return (0);
	slen = ftt_strlen(s);
	if (start > slen)
		return (ftt_strdup(""));
	if (len >= slen - start)
		len = slen - start;
	r = malloc(sizeof(char) * (len + 1));
	if (!r)
		return (0);
	ftt_strlcpy(r, s + start, len + 1);
	return (r);
}
