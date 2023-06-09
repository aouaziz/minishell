/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_dup_ds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 09:24:50 by mel-garr          #+#    #+#             */
/*   Updated: 2023/06/09 09:50:20 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int doubl_str_len(char **str)
{
    int i;

    i = 0;
    if (!str)
        return(0);
    while (str[i])
        i++;
    return (i);
}

char **ftt_strdup_2(char **str)
{
    int len;
    char **ret;
    int i;

    i = 0;
    if (!str)
        return (NULL);
    len = doubl_str_len(str);
    ret = (char **)malloc(sizeof(char *) * (len + 1));
    if (!ret)
        return (ftt_print_fd(2, "dup_an_env\n"), NULL);
    while (str[i])
    {
        ret[i] = ftt_strdup(str[i]);
        i++;
    }
    ret[i] = NULL;
    return (ret);
}