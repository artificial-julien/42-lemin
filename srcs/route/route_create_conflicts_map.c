/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_create_conflicts_map.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:47:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 21:14:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_bool	contains_node(t_room *node, t_route *route)
{
	t_glist	*curr;

	curr = route->rooms;
	while (curr != NULL)
	{
		if (curr->room == node)
			return (true);
		curr = curr->next;
	}
	return (false);
}

/*
**	TODO: Optimize (avoid duplicate tests)
*/

static t_bool	have_conflicts(t_route *route_a, t_route *route_b)
{
	t_glist	*curr;

	curr = route_a->rooms;
	while (curr != NULL)
	{
		if (curr->room->type == standard && contains_node(curr->room, route_b))
		{
			return (true);
		}
		curr = curr->next;
	}
	return (false);
}

void			route_create_conflicts_map(t_route *route, t_glist *routes,
	int count)
{
	t_glist	*curr;
	t_bool	conflict;

	route->conflicts = bitmap_new(count);
	curr = routes;
	while (curr != NULL)
	{
		if (curr->route != route)
		{
			conflict = have_conflicts(curr->route, route);
			if (conflict)
				bitmap_set(route->conflicts, curr->route->id_route);
		}
		curr = curr->next;
	}
}
