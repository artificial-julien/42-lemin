/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:32:33 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/08 16:55:03 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	size_t	i;

	i = 0;
	while (1)
	{
		if (((unsigned char*)str)[i] == (unsigned char)character)
			return ((char*)(str + i));
		if (((unsigned char*)str)[i] == '\0')
			return (NULL);
		i++;
	}
}
