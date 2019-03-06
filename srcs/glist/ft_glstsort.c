/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:21:05 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 19:38:32 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Swaps the content of the specified elements.
*/

static void		swap(t_glist *a, t_glist *b)
{
	void	*content;
	size_t	content_size;

	content = a->gen.content;
	content_size = a->content_size;
	a->gen.content = b->gen.content;
	a->content_size = b->content_size;
	b->gen.content = content;
	b->content_size = content_size;
}

/*
**	Runs one pass. Returns true if all elements are ordered.
*/

static t_bool	pass(t_glist *list, int (*cmp)(void*, void*))
{
	t_bool	res;
	t_glist	*curr;

	res = true;
	curr = list;
	while (curr != NULL && curr->next != NULL)
	{
		if (cmp(curr->gen.content, curr->next->gen.content))
		{
			res = false;
			swap(curr, curr->next);
		}
		curr = curr->next;
	}
	return (res);
}

/*
**	Linked-list bubble sort.
**	Sorts over content. Do not swap pointers.
*/

void			ft_glstsort(t_glist *list, int (*cmp)(void*, void*))
{
	t_glist	*curr;

	curr = list;
	while (curr != NULL)
	{
		if (pass(curr, cmp))
			return ;
		curr = curr->next;
	}
}
