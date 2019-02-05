/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:55:39 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 11:47:30 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	reverse_list(t_glist **begin_list)
{
	t_glist	*current;
	t_glist	*previous;
	t_glist	*next;

	current = *begin_list;
	previous = 0;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*begin_list = previous;
}

/*
**	Returns a copy of all list elements.
**	Copies the content pointers.
*/

t_glist		*ft_glstcpy(t_glist *src)
{
	t_glist	*res;
	t_glist	*curr;
	t_glist	*new;

	curr = src;
	while (curr != NULL)
	{
		new = ft_glstnew(curr->content, curr->content_size);
		ft_glstadd(&res, new);
		curr = curr->next;
	}
	reverse_list(&res);

	return (res);
}
