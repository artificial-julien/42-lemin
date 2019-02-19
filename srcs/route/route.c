/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:54:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/07 16:22:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Creat a new t_route.
*/

t_route	*route_new(void)
{
	t_route	*res;

	res = ft_memalloc(sizeof(t_route));
	return (res);
}

/*
** return comparaison between route a and b
*/

int		route_cmp(void *a, void *b)
{
	t_route *route_a;
	t_route *route_b;

	route_a = (t_route*)a;
	route_b = (t_route*)b;
	if (route_a->len == route_b->len)
		return (0);
	else
	{
		return ((route_a->len < route_b->len) ? -1 : 1);
	}
}

/*
** Return if the two  routes are equals or not.
*/

t_bool	route_equals(t_route *route_a, t_route *route_b)
{
	if (!route_a || !route_b)
		return (false);
	if ((route_a->id_route == route_b->id_route)
		&& (route_a->len == route_b->len))
	{
		return (true);
	}
	else
		return (false);
}

/*
**	Function to test if the two route has conflict.
*/

t_bool	route_has_conflict(t_route *a, t_route *b)
{
	t_bool	res;

	res = false;
	if (route_equals(a, b) == true)
		return (true);
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
	ft_fprintf(2, "Route #%d | length: %d |\t", route->id_route, route->len);
	print_nodes(route->rooms);
}
