/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 07:24:40 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/10 09:50:15 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void        print_err_env(char *str)
{
  ftt_print_fd(2, "bash: export: ");
  ftt_print_fd(2, str);
  ftt_print_fd(2, ": not a valid indentifier\n");
}