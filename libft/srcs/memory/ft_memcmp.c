/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:08:08 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/05 17:12:55 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (i < num)
	{
		c1 = ((unsigned char*)ptr1)[i];
		c2 = ((unsigned char*)ptr2)[i];
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
