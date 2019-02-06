/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 14:47:20 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 15:02:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	cmp(void *ptr_a, void *ptr_b)
{
	t_route	*a;
	t_route	*b;

	a = (t_route*)ptr_a;
	b = (t_route*)ptr_b;
	return (a->len - b->len);
}

/*
**	Sorts the routes of the specified group by size.
*/

void		sort_routes(t_group *group)
{
	ft_glstsort(group->routes, cmp);
}
