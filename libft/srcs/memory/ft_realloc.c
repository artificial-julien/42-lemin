/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:25:35 by agoulas           #+#    #+#             */
/*   Updated: 2018/01/21 17:56:05 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;
	size_t	ptrsize;
	void	*ret;

	if (ptr == 0)
		return (ft_memalloc(size));
	ptrsize = sizeof(ptr);
	if (size <= ptrsize)
		return (ptr);
	if ((newptr = (char*)ft_memalloc(ptrsize
					* (ft_strlen((char*)ptr) + size))) == NULL)
		return (NULL);
	if ((ret = ft_memcpy(newptr, ptr, ft_strlen((char*)ptr))) == NULL)
		return (ptr);
	free(ptr);
	return (newptr);
}
