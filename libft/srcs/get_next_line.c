/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 08:53:16 by aouaziz           #+#    #+#             */
/*   Updated: 2023/02/18 22:58:29 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_save(char *s)
{
	int		i;
	int		b;
	char	*save;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	save = malloc(sizeof(char) * (get_strlen(s) - i + 1));
	if (!s)
		return (0);
	i++;
	b = 0;
	while (s[i])
		save[b++] = s[i++];
	save[b] = '\0';
	free(s);
	return (save);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*save;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	save = malloc(sizeof(char) * (i + 2));
	if (!save)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		save[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		save[i] = s[i];
		i++;
	}
	save[i] = '\0';
	return (save);
}

char	*read_buf(int fd, char *s)
{
	char	*buff;
	int		r;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	r = 1;
	while (!get_strchr(s, '\n') && r != 0)
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == -1)
		{
			free(buff);
			free(s);
			return (0);
		}
		buff[r] = '\0';
		s = get_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		write(1, "something wrong fd (*_*)!!!", 27);
		exit(1);
	}
	s = read_buf(fd, s);
	if (!s)
		return (0);
	line = ft_get_line(s);
	s = get_save(s);
	return (line);
}
