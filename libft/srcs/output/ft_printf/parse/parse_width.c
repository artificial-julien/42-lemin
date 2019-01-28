/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:52:21 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 18:06:06 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_width(t_formatinfo *info,
						const char *restrict format,
						int *pos)
{
	int	width;

	if (parse_number(format, pos, &width))
	{
		info->width = width;
		return (1);
	}
	return (0);
}
