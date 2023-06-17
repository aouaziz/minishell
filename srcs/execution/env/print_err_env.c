/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouaziz <aouaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:40 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/17 07:23:40 by aouaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void        print_err_env(char *str)
{
  ftt_print_fd(2, "minishell: export: ");
  ftt_print_fd(2, str);
  ftt_print_fd(2, ": not a valid indentifier\n");
  shell->g_status = 1;
}