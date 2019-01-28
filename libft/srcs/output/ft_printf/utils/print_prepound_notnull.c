/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prepound_notnull.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:00:02 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 12:22:43 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints the specified prepound string if the value is not null.
*/

void	print_prepound_notnull(t_formatinfo *info, char *str,
								va_list ap, t_output *out)
{
	if (!value_is_zero(info, ap))
		out_putchar_len(out, str, ft_strlen(str));
}
