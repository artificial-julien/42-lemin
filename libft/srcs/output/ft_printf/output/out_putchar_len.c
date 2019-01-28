/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:37:52 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 15:36:11 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	out_putchar_len(t_output *output, char *ptr, size_t size)
{
	int	i;

	i = 0;
	while ((size_t)i < size)
	{
		out_putchar(output, ptr[i]);
		i++;
	}
}
