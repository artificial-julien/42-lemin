/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_build.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:38:13 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 15:28:41 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		route_cmp_len(void *a, void *b)
{
	t_route	*route_a;
	t_route	*route_b;

	route_a = (t_route*)a;
	route_b = (t_route*)b;
	return (route_a->len - route_b->len);
}

static int		routes_count(t_room *start)
{
	int		res;
	t_glist	*curr;

	res = 0;
	curr = start->links;
	while (curr != NULL)
	{
		if (curr->room->next != NULL || curr->room->type == end)
		{
			res++;
		}
		curr = curr->next;
	}
	return (res);
}

static void		create_routes(t_lem_in *lem_in, t_group *group)
{
	t_glist	*curr;
	t_route	*route;
	int		i;

	i = 0;
	curr = lem_in->start->links;
	while (curr != NULL)
	{
		if (curr->room->next != NULL || curr->room->type == end)
		{
			route = route_build(lem_in->start, curr->room);
			group->routes[i] = route;
			i++;
		}
		curr = curr->next;
	}
}

/*
**	Creates a new group of routes using the outgoing connections from the
**	start node.
*/

t_group			*group_build(t_lem_in *lem_in)
{
	t_group	*res;

	res = ft_memalloc(sizeof(t_group));
	res->route_count = routes_count(lem_in->start);
	res->routes = ft_safe_malloc(sizeof(t_route*) * res->route_count);
	res->ants_distribution = ft_memalloc(sizeof(int) * res->route_count);
	create_routes(lem_in, res);
	array_sort((void**)res->routes, res->route_count, route_cmp_len);
	distribute_ants(res, lem_in->total_ants, res->ants_distribution);
	res->total_rounds =
		res->routes[0]->len
		+ (lem_in->total_ants / res->route_count)
		+ ((lem_in->total_ants % res->route_count) > 0 ? 1 : 0)
		- 1;
	return (res);
}
