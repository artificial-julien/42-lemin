/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:59:20 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 17:53:02 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *result;

	result = ft_memalloc(size + 1);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size + 1);
	return (result);
}
