/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:51:12 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 17:57:53 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_number(const char *restrict format, int *pos, int *num)
{
	int	digit;

	if (!ft_isdigit(format[*pos]))
		return (0);
	*num = 0;
	while (ft_isdigit(format[*pos]))
	{
		digit = format[*pos] - '0';
		(*num) *= 10;
		(*num) += digit;
		(*pos)++;
	}
	return (1);
}
