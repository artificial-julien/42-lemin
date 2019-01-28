/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_del_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:52:42 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 15:14:38 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lst_del_one(t_list *curr, void *value, size_t size)
{
	t_list	*tmp;

	tmp = NULL;
	if (curr == NULL)
		return (NULL);
	if (value == NULL && curr->content == NULL && curr->content_size == 0
			&& size == 0)
	{
		tmp = curr->next;
		free(curr);
		return (tmp);
	}
	if (curr->content_size == size &&
			(ft_strncmp(curr->content, value, ft_strlen(value)) == 0) &&
			(ft_strlen(curr->content) == ft_strlen(value)))
	{
		tmp = curr->next;
		free(curr->content);
		free(curr);
		return (tmp);
	}
	curr->next = ft_lst_del_one(curr->next, value, size);
	return (curr);
}
