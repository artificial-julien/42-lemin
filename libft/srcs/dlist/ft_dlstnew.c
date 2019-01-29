/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:25:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 14:00:17 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*result;
	void	*new_content;

	result = malloc(sizeof(t_dlist));
	if (result == NULL)
		return (NULL);
	result->content = (void*)content;
	if (content == NULL)
	{
		result->content_size = 0;
		result->content = NULL;
	}
	else
	{
		new_content = malloc(content_size);
		if (new_content == NULL)
			return (NULL);
		ft_memcpy(new_content, content, content_size);
		result->content = new_content;
		result->content_size = content_size;
	}
	result->next = NULL;
	result->prev = NULL;
	return (result);
}
