/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:43:05 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/12 16:00:58 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_formatinfo *info, va_list ap, t_output *out)
{
	int		c;

	(void)info;
	c = va_arg(ap, int);
	out_putchar(out, c);
}
