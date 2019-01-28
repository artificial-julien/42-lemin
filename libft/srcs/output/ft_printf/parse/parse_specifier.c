/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:53:22 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/14 13:27:02 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_specifier	get_specifier(char c)
{
	t_specifier	specifiers[256];

	ft_bzero(&specifiers, sizeof(specifiers));
	specifiers['i'] = spec_int;
	specifiers['d'] = spec_int;
	specifiers['u'] = spec_uint;
	specifiers['x'] = spec_hex;
	specifiers['X'] = spec_hexup;
	specifiers['o'] = spec_octal;
	specifiers['f'] = spec_float;
	specifiers['F'] = spec_float;
	specifiers['s'] = spec_str;
	specifiers['c'] = spec_char;
	specifiers['p'] = spec_ptr;
	specifiers['%'] = spec_percent;
	return (specifiers[(int)c]);
}

int					parse_specifier(t_formatinfo *info,
							const char *restrict format,
							int *pos)
{
	char		c;
	t_specifier	spec;

	c = format[*pos];
	spec = get_specifier(c);
	if (spec == spec_none)
		return (0);
	(*pos)++;
	info->specifier = spec;
	return (1);
}
