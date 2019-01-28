/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 23:30:23 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/08 18:17:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_len;
	size_t	little_len;
	size_t	i;

	big_len = ft_strlen((char*)big);
	little_len = ft_strlen((char*)little);
	if (little_len == 0)
	{
		return ((char*)big);
	}
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (!ft_strncmp((char*)big + i, (char*)little, little_len))
		{
			return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
