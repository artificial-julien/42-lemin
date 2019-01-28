/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:02:58 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/13 14:55:55 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_float_core(double dnum, double div, t_output *out)
{
	int		digit;
	double	tmp;

	while (div >= 1.0f)
	{
		tmp = dnum / div;
		digit = ((int)tmp) % 10;
		out_putchar(out, '0' + digit);
		dnum -= digit * div;
		div /= 10.0f;
	}
}

static double	get_start_div(double dnum)
{
	double	i;

	i = 0;
	while (dnum >= 10.0f)
	{
		dnum /= 10;
		i++;
	}
	return (ft_powf(10, i));
}

/*
**	Loads a float type variable using va_arg() and ap.
**	Returns the number of printed characters.
*/

void			print_float(t_formatinfo *info, va_list ap, t_output *out)
{
	double	num;
	double	start;

	(void)info;
	num = va_arg(ap, double);
	if (num < 0)
	{
		out_putchar(out, '-');
		num *= -1;
	}
	start = get_start_div(num);
	print_float_core(num, start, out);
}
