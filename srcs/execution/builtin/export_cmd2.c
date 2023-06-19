/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:17:39 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/19 06:25:47 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_get_va_lue(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
		i++;
	if (!str[i])
		return (ftt_strdup(""));
	if (str[i] == '+' && str[i + 1] == '=')
		i = i + 2;
	else if (str[i] == '=')
		i++;
	return (ft_substr(str, i, ftt_strlen(str) - i + 1));
}

char	*ft_get_name(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != '+')
		i++;
	return (ftt_substr(str, 0, i));
}

void	fill_env_list_add_back(char *name, char *value)
{
	t_env	*tmp;

	tmp = ft_env_lst_new(name, value);
	ft_env_lstadd_back(&g_shell->env_list, tmp);
}

int	ft_exist(char *str)
{
	t_env	*tmp;

	tmp = g_shell->env_list;
	while (tmp)
	{
		if (ft_strcmp(tmp->env_name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (2);
}

void	change_status_export(int status, char *name)
{
	t_env	*tmp;

	tmp = g_shell->env_list;
	while (tmp)
	{
		if (ft_strcmp(name, tmp->env_name) == 0)
		{
			tmp->status = status;
			break ;
		}
		tmp = tmp->next;
	}
}
