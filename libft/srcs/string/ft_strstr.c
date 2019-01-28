/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:39:45 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/20 16:00:28 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	int len;

	len = ft_strlen(to_find);
	if (len == 0)
	{
		return ((char*)str);
	}
	while (*str)
	{
		if (!ft_strncmp(str, to_find, len))
		{
			return ((char*)str);
		}
		str++;
	}
	return (0);
}
