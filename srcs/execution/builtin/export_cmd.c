/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 23:29:30 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/22 22:08:49 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export_element(char *str, int l)
{
	char	*name;
	char	*value;
	int		exist;

	name = ft_get_name(str);
	value = ft_get_va_lue(str);
	exist = ft_exist(name);
	if (exist == 2)
		fill_env_list_add_back(name, value);
	else if (exist == 1 && l == 1)
		return ;
	else if (exist == 1 && l == 3)
		value = ftt_strjoin(ft_get_value(name), value);
	ft_env_change_value(name, value);
	do_status(exist, l, name);
	free(value);
	free(name);
}

void	export_env(char **args)
{
	int	i;
	int	l;

	i = 1;
	while (args[i])
	{
		l = valid_arg(args[i]);
		if (l > -1)
			export_element(args[i], l);
		else
			printf("minishell: export: `%s': not a valid identifier \n",
				args[i]);
		i++;
	}
}

void	ppprint_env_list(void)
{
	t_env	*tmp;

	tmp = g_shell->env_list;
	while (tmp)
	{
		if (tmp->status == 0)
			printf("declare -x %s=\"%s\"\n", tmp->env_name, tmp->env_value);
		else if (tmp->status == -1)
			printf("declare -x %s\n", tmp->env_name);
		tmp = tmp->next;
	}
}

void	env_export_cmd(void)
{
	t_env	*tmp;
	t_env	*n_head;
	char	*tmp_name;
	char	*tmp_value;

	tmp = g_shell->env_list;
	while (tmp)
	{
		n_head = tmp->next;
		while (tmp && n_head)
		{
			if (ft_strcmp(tmp->env_name, n_head->env_name) > 0)
			{
				tmp_name = tmp->env_name;
				tmp_value = tmp->env_value;
				tmp->env_name = n_head->env_name;
				tmp->env_value = n_head->env_value;
				n_head->env_name = tmp_name;
				n_head->env_value = tmp_value;
			}
			n_head = n_head->next;
		}
		tmp = tmp->next;
	}
	ppprint_env_list();
}

void	export_cmd(char **args)
{
	pid_t	fid;

	if (!args[1])
	{
		fid = fork();
		if (fid == 0)
		{
			env_export_cmd();
			exit(0);
		}
		else
			wait(0);
		return ;
	}
	else
		export_env(args);
}
