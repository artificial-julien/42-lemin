/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:53:02 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 18:08:44 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_length(t_formatinfo *info,
						const char *restrict format,
						int *pos)
{
	char		*str;
	t_length	len;

	str = (char*)format + (*pos);
	if (!ft_strncmp(str, "hh", 2))
		len = len_char;
	else if (!ft_strncmp(str, "h", 1))
		len = len_short;
	else if (!ft_strncmp(str, "ll", 2))
		len = len_llong;
	else if (!ft_strncmp(str, "l", 1))
		len = len_long;
	else
		return (0);
	if (len == len_char || len == len_llong)
		(*pos) += 2;
	else if (len == len_long || len == len_short)
		(*pos) += 1;
	info->length = len;
	return (1);
}
