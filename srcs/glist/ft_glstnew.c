/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:25:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/30 18:33:09 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist	*ft_glstnew(void const *content, size_t content_size)
{
	t_glist	*result;

	result = malloc(sizeof(t_glist));
	if (result == NULL)
	{
		return (NULL);
	}
	result->content = (void*)content;
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
