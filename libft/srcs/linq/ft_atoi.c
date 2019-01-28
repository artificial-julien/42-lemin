/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:20:31 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 15:56:47 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_sign(char const *str, int *i)
{
	if (str[(*i)] == '-')
	{
		(*i)++;
		return (-1);
	}
	if (str[(*i)] == '+')
	{
		(*i)++;
	}
	return (1);
}

int			ft_atoi(char const *str)
{
	long	result;
	int		i;
	int		sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	sign = get_sign(str, &i);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		if (result < 0)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		i++;
	}
	return (sign * result);
}
