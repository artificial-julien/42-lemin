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
** Return pointer to insert new
*/

static void	find_lst_index(t_glist **curr, t_glist **curr_prec, t_glist **new, int (*cmp)(void*, void*))
{
	while ((*curr) && cmp((*curr)->content, (*new)->content) > 0)
	{
		(*curr_prec) = (*curr);
		(*curr) = (*curr)->next;
	}
}

/*
**	insert in the glist in orderof the function cmp.
*/

void		ft_glstinsert(t_glist **dest, t_glist *new, int (*cmp)(void*, void*))
{
	t_glist *curr;
	t_glist *curr_prec;

	curr = (*dest);
	curr_prec = (*dest);
	if (new == NULL)
		return ;
	find_lst_index(&curr, &curr_prec, &new, (*cmp));
	new->next = curr;
	if (curr_prec != NULL)
	{
		curr_prec->next = new;
	}
	else
	{
		*dest = new;
	}
}

