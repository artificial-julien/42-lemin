/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:30:55 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 12:12:21 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE			"01234567"
#define BASE_LEN		8
#define PREPOUND		"0"
#define PREPOUND_LEN	1

#define BUF_SIZE		255

void		print_octal(t_formatinfo *info, va_list ap, t_output *output)
{
	t_output	output2;
	char		buf[BUF_SIZE];
	va_list		ap2;

	if (info->flags & FLAG_PREPOUND)
	{
		va_copy(ap2, ap);
		out_init(&output2);
		output2.buf = buf;
		print_number_generic(info, ap2, BASE, &output2);
		if (output2.size == 0 || buf[0] != '0')
			out_putchar_len(output, PREPOUND, PREPOUND_LEN);
	}
	print_number_generic(info, ap, BASE, output);
}
