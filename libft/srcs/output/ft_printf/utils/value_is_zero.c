/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_is_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:51:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 11:51:38 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		value_is_zero(t_formatinfo *info, va_list ap)
{
	t_u64	num;
	va_list	ap2;

	va_copy(ap2, ap);
	num = read_argument_unsigned(info, ap2);
	return (num == 0);
}
