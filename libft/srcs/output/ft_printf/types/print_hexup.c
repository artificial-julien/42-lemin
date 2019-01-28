/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:38:52 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/14 14:02:59 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define BASE		"0123456789ABCDEF"
#define BASE_LEN	16
#define PREPOUND	"0X"

void		print_hexup(t_formatinfo *info, va_list ap, t_output *output)
{
	if (info->flags & FLAG_PREPOUND)
		print_prepound_notnull(info, PREPOUND, ap, output);
	print_number_generic(info, ap, BASE, output);
}
