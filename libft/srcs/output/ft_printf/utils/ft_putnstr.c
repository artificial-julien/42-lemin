/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:49:00 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/10 11:03:05 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints up to max characters.
*/

int	ft_putnstr(char *str, int max)
{
	int	i;

	i = 0;
	while (i < max && str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}
