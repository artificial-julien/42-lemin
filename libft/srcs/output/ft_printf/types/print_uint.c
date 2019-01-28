/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:08:48 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/11 13:40:06 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"0123456789"
#define BASE_LEN	10

void		print_uint(t_formatinfo *info, va_list ap, t_output *output)
{
	print_number_generic(info, ap, BASE, output);
}
