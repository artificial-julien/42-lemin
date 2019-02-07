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
void	ft_glstinsert(t_glist **dest, t_glist *new, int (*cmp)(void*, void*))
{
	t_glist *curr;
	int		cmp_curr;

	curr = *dest;
	if (*dest == NULL)
	{
		*dest = new;
		new->next = NULL;
	}
	else if (curr && (cmp_curr = cmp((void*)curr->content, (void*)new->content)) > 0)
	{
		new->next = curr;
		*dest = new;
		return ;
	}
	else
	{
		while (curr && curr->next != NULL && (cmp_curr = cmp(curr->next->content, new->content)) <= 0)
			curr = curr->next;
		if (curr == NULL)
			curr = new;
		else if (curr && curr->next == NULL)
			curr->next = new;
		else
		{
			new = curr->next;
			curr->next = new;

		}
	}


}*/

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
	if (*dest == NULL)
	{
		*dest = new;
		return ;
	}
	find_lst_index(&curr, &curr_prec, &new, (*cmp));
	if (curr_prec != NULL)
	{
		curr_prec = new;
		new->next = curr;
	}
	else
	{
		curr_prec = new;
	}
}

