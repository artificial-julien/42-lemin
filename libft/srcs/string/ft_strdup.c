/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 18:43:25 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 17:53:00 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*result;
	int		len;

	len = ft_strlen(src);
	result = ft_memalloc(len + 1);
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, src);
	return (result);
}
