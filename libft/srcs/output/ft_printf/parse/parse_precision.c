/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:40 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 18:06:52 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_precision(t_formatinfo *info,
							const char *restrict format,
							int *pos)
{
	int	precision;

	if (format[*pos] == '.')
	{
		(*pos)++;
		if (!parse_number(format, pos, &precision))
			precision = 0;
		info->precision = precision;
		info->flags |= FLAG_HASPRECISION;
		return (1);
	}
	return (0);
}
