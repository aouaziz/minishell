/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_strncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:58:51 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/18 10:14:50 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ftt_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (0);
	if (i == n)
		return (0);
	return (1);
}

int	ftt_strcmp(char *s1, char *s2)
{
	size_t			i;
	size_t			n;
	unsigned char	*s;
	unsigned char	*d;

	i = 0;
	if (!s1 || !s2)
		return (1);
	n = ftt_strlen(s1);
	s = (unsigned char *)s1;
	d = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s[i] != '\0' && d[i] != '\0' && s[i] == d[i] && i < n - 1)
		i++;
	return (s[i] - d[i]);
}
