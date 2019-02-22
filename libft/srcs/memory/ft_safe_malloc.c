/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:25:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 17:01:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_safe_malloc(size_t size)
{
	void	*ptr;

	if ((ptr = (void*)malloc(size)) == NULL)
	{
		ft_printf("ERROR\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
