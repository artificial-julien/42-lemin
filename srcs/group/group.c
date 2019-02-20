/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/11 16:11:08 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function of initialisation of a new group_creat
*/

t_group	*group_new(void)
{
	t_group	*res;

	res = ft_memalloc(sizeof(t_group));
	res->count = 0;
	res->high_len = 0;
	res->low_len = 0;
	return (res);
}

/*
** Function that add a route to a group
** and actualize the information of the group
*/

void	group_add_route(t_group *group, t_route *route)
{
	t_glist *tmp;

	tmp = NULL;
	if (route != NULL)
	{
		tmp = ft_glstnew(route, sizeof(route));
		ft_glstinsert(&group->routes, tmp, &route_cmp);
		group->count++;
		if (group->low_len == 0 || group->low_len > route->len)
			group->low_len = route->len;
		if (group->high_len == 0 || group->high_len < route->len)
			group->high_len = route->len;
	}
}

/*
** Return true if a route is in the glist of the group ,else return false.
*/

t_bool	group_has_route(t_group *group, t_route *route)
{
	t_glist	*group_routes;
	t_route	*curr;

	group_routes = group->routes;
	curr = NULL;
	while (group_routes != NULL && (curr = group_routes->route) != NULL)
	{
		if (route_equals(curr, route) == true)
			return (true);
		group_routes = group_routes->next;
	}
	return (false);
}

/*
**	Returns true if both groups are identical.
*/

t_bool	group_equals(t_group *group_a, t_group *group_b)
{
	t_glist	*group_routes_a;
	t_route	*route_a;
	int		cpt;

	cpt = 0;
	if (group_a->count == group_b->count
		&& group_a->high_len == group_b->high_len
		&& group_a->low_len == group_b->low_len)
	{
		group_routes_a = group_a->routes;
		while (group_routes_a != NULL)
		{
			route_a = group_routes_a->route;
			if (group_has_route(group_b, route_a) == true)
				cpt++;
			group_routes_a = group_routes_a->next;
		}
		if (cpt == group_a->count)
			return (true);
		else
			return (false);
	}
	else
		return (false);
}

/*
**	Free group's elements.
*/

void	group_free(void *content, size_t size)
{
	t_group	*group;

	(void)size;
	group = (t_group*)content;
	ft_glstdel(&group->routes, NULL);
	free(group);
}
