/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:54:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 14:40:20 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_route	*route_new(void)
{
	t_route	*res;

	res = ft_memalloc(sizeof(t_route));
	return (res);
}

/*
**	TODO: Optimize (avoid duplicate tests)
*/

void	route_create_conflicts_map(t_route *route, t_glist *routes)
{
	t_glist	*curr;
	t_bool	conflict;

	curr = routes;
	while (curr != NULL)
	{
		conflict = route_cmp_conflit(curr->route, route);
		if (conflict)
			bitmap_set(route->conflicts, curr->route->id_route);
		curr = curr->next;
	}
}

t_bool	route_cmp_conflit(t_route *route_a, t_route *route_b)
{
	t_glist	*lst_a;
	t_glist	*lst_b;
	t_room	*room_a;
	t_room	*room_b;

	lst_a = route_a->rooms;
	lst_b = route_b->rooms;
	while (lst_a && lst_a->content)
	{
		room_a = lst_a->content;
		while (room_a && lst_b && lst_b->content)
		{
			room_b = lst_b->content;
			if (room_a->name == room_b->name
				&& room_a->type == standard
				&& room_b->type == standard)
				return (true);
			lst_b = lst_b->next;
		}
		lst_a = lst_a->next;
	}
	return (false);
}

t_bool	route_has_conflict(t_route *a, t_route *b)
{
	t_bool	res;

	res = bitmap_get(a->conflicts, b->id_route);
	return (res);
}

/*
**	Free route's elements.
*/

void	route_free(void *content, size_t size)
{
	t_route	*route;

	(void)size;
	route = (t_route*)content;
	bitmap_free(route->conflicts);
	ft_glstdel(&route->rooms, NULL);
	free(route);
}

/*
**	Prints the specified route.
**	Debug purposes.
*/

void	route_print(t_route *route)
{
	print_nodes(route->rooms);
}
