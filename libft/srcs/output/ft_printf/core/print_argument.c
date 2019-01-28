/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:31:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/21 17:20:34 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Returns the argument type specific function that prints the argument.
*/

static void	(*get_func(t_specifier spec))(t_formatinfo*, va_list, t_output*)
{
	void		(*func[SPEC_COUNT])(t_formatinfo*, va_list, t_output*);

	func[spec_int] = print_int;
	func[spec_uint] = print_uint;
	func[spec_octal] = print_octal;
	func[spec_hex] = print_hex;
	func[spec_hexup] = print_hexup;
	func[spec_float] = print_float;
	func[spec_str] = print_str;
	func[spec_char] = print_char;
	func[spec_percent] = print_percent;
	func[spec_ptr] = print_ptr;
	return (func[spec]);
}

/*
**	Prints the padding using the total existant len.
*/

static void	print_space_padding(t_formatinfo *formatinfo,
								int len,
								t_output *out)
{
	char	padchar;

	if (len >= formatinfo->width)
		return ;
	if (formatinfo->flags & FLAG_ZERO)
		padchar = '0';
	else
		padchar = ' ';
	out_fill(out, (formatinfo->width - len), padchar);
}

/*
**	Selects the right function to print the argument.
**	Returns the number of printed characters.
*/

int			print_argument(int fd, t_formatinfo *formatinfo, va_list ap)
{
	void		(*print_func)(t_formatinfo*, va_list, t_output*);
	t_output	output;
	int			output_size;
	va_list		ap2;

	va_copy(ap2, ap);
	print_func = get_func(formatinfo->specifier);
	out_init(&output);
	print_func(formatinfo, ap, &output);
	output_size = output.size;
	out_init(&output);
	output.fd = fd;
	if (formatinfo->flags & FLAG_MINUS)
	{
		print_func(formatinfo, ap2, &output);
		print_space_padding(formatinfo, output_size, &output);
	}
	else
	{
		print_space_padding(formatinfo, output_size, &output);
		print_func(formatinfo, ap2, &output);
	}
	return (output.size);
}
