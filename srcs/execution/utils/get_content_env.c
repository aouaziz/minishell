/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_content_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 08:41:03 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/24 20:59:03 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_indice_env(char **env, char *path)
{
	int	i;
	int	len;

	i = 0;
	len = ftt_strlen(path);
	while (env[i])
	{
		if (ftt_strncmp(env[i], path, len) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_content_env(char **env, char *path)
{
	return (env[get_indice_env(env, path)]);
}

int	get_indice_path(char **env, char *path)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ftt_strncmp(env[i], path, 4) == 0)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_content_path(char **env, char *path)
{
	return (env[get_indice_path(env, path)]);
}
