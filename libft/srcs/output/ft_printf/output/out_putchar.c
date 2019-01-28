/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:54:09 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/18 12:05:01 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_putchar(t_output *output, char c)
{
	if (output->fd >= 0)
		ft_putchar_fd(c, output->fd);
	if (output->buf != NULL)
		output->buf[output->size] = c;
	output->size++;
}
