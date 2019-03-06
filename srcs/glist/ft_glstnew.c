/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:25:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 19:37:14 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist	*ft_glstnew(void const *content, size_t content_size)
{
	t_glist	*result;

	result = ft_memalloc(sizeof(t_glist));
	result->gen.content = (void*)content;
	if (content == NULL)
	{
		result->content_size = 0;
	}
	else
	{
		result->content_size = content_size;
	}
	result->next = NULL;
	return (result);
}
