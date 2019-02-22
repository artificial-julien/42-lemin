/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:54:17 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 15:14:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewchar(void const *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if ((new = (t_list*)ft_safe_malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = NULL;
		if ((new->content = ft_strdup(content)) == NULL)
			return (NULL);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
