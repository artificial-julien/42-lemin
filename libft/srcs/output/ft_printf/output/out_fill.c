/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 15:59:35 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/13 15:59:40 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		out_fill(t_output *output, int count, char c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		out_putchar(output, c);
		i++;
	}
}
