/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstinsert.c          ß                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/05 13:22:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Inserts in the glist in order of the function cmp.
*/

void				ft_glstinsert(t_glist **dest, t_glist *new, int (*cmp)(void*, void*))
{
	t_glist	*curr;
	t_glist  *curr_prev;
	int tmp;

	curr_prev = NULL;
	curr = (*dest);
	while ((curr))
	{
		if ((tmp = cmp((curr)->content, (new)->content)) <= 0)
			break ;
		(curr_prev) = (curr);
		(curr) = (curr)->next;
	}
	new->next = curr;
	if (curr_prev != NULL)
	{
		curr_prev->next = new;
	}
	else
	{
		*dest = new;
	}
}

