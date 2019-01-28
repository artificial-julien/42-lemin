/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 17:44:58 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/05 16:14:54 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	tmp;

	if (nb < 0)
	{
		tmp = (unsigned int)-nb;
		ft_putchar_fd('-', fd);
	}
	else
	{
		tmp = (unsigned int)nb;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd((int)(tmp / 10), fd);
	}
	ft_putchar_fd(tmp % 10 + '0', fd);
}
