/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:52 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/14 14:03:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE			"0123456789abcdef"
#define BASE_LEN		16
#define PREPOUND		"0x"
#define PREPOUND_LEN	2

void		print_ptr(t_formatinfo *info, va_list ap, t_output *output)
{
	info->length = len_ptr;
	out_putchar_len(output, PREPOUND, PREPOUND_LEN);
	print_number_generic(info, ap, BASE, output);
}
