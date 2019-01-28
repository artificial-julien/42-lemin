/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 18:47:54 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/13 17:59:43 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_64	read_argument_signed(t_formatinfo *info, va_list ap)
{
	t_64	num;

	if (info->length == len_char)
		num = (char)(va_arg(ap, int));
	else if (info->length == len_short)
		num = (short)(va_arg(ap, int));
	else if (info->length == len_long)
		num = (long)(va_arg(ap, long));
	else if (info->length == len_llong)
		num = (long long)(va_arg(ap, long long));
	else if (info->length == len_ptr)
		num = (t_64)(va_arg(ap, void*));
	else
		num = (int)(va_arg(ap, int));
	return (num);
}

t_u64	read_argument_unsigned(t_formatinfo *info, va_list ap)
{
	t_u64	num;

	if (info->length == len_char)
		num = (unsigned char)(va_arg(ap, unsigned int));
	else if (info->length == len_short)
		num = (unsigned short)(va_arg(ap, unsigned int));
	else if (info->length == len_long)
		num = (unsigned long)(va_arg(ap, unsigned long));
	else if (info->length == len_llong)
		num = (unsigned long long)(va_arg(ap, unsigned long long));
	else if (info->length == len_ptr)
		num = (t_u64)(va_arg(ap, void*));
	else
		num = (unsigned int)(va_arg(ap, unsigned int));
	return (num);
}
