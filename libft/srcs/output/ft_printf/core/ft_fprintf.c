/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:05:30 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/21 17:44:38 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Parse the current argument starting with "%" and prints it.
*/

static int	parse_and_print_argument(int fd,
									const char *restrict format,
									int *pos,
									va_list ap)
{
	t_formatinfo	formatinfo;

	ft_bzero(&formatinfo, sizeof(formatinfo));
	parse(format, pos, &formatinfo);
	if (formatinfo.specifier == spec_none)
		return (0);
	return (print_argument(fd, &formatinfo, ap));
}

static int	ft_fprintf_core(int fd, const char *restrict format, va_list ap)
{
	int		output_size;
	int		pos;

	pos = 0;
	output_size = 0;
	while (format[pos] != '\0')
	{
		if (format[pos] == '%')
		{
			pos++;
			output_size += parse_and_print_argument(fd, format, &pos, ap);
		}
		else
		{
			ft_putchar_fd(format[pos], fd);
			pos++;
			output_size++;
		}
	}
	va_end(ap);
	return (output_size);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_fprintf_core(STDOUT_FILENO, format, ap));
}

int			ft_fprintf(int fd, const char *restrict format, ...)
{
	va_list	ap;

	va_start(ap, format);
	return (ft_fprintf_core(fd, format, ap));
}
