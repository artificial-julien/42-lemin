/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:22:53 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/13 15:52:10 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints the padding characters if len < width
**	Returns the total number of printed characters
*/

void	print_padding(t_formatinfo *formatinfo, int len, t_output *output)
{
	char	padchar;

	if (len >= formatinfo->width)
		return ;
	if (formatinfo->flags & FLAG_ZERO)
		padchar = '0';
	else
		padchar = ' ';
	out_fill(output, (formatinfo->width - len), padchar);
}
