/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:55:39 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 19:37:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns a copy of all list elements.
**	Copies the content pointers.
**	Output is in reverse order (as required by route_creator).
*/

t_glist		*ft_glstcpy(t_glist *src)
{
	t_glist	*res;
	t_glist	*curr;
	t_glist	*new;

	res = NULL;
	curr = src;
	while (curr != NULL)
	{
		new = ft_glstnew(curr->gen.content, curr->content_size);
		ft_glstadd(&res, new);
		curr = curr->next;
	}
	return (res);
}
