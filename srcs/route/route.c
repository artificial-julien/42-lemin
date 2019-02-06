/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:54:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 20:23:58 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_route	*route_new(void)
{
	t_route	*res;

	res = ft_memalloc(sizeof(t_route));
	return (res);
}

t_bool	route_equals(t_route *route_a, t_route *route_b)
{
	if (!route_a || !route_b)
		return (false);
	if (route_a->id_route == route_b->id_route
		&& route_a->len == route_b->len)
	{
		return (true);
	}
	else
		return (false);
}

/*
**	Function
*/

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
	ft_printf("Route #%d\t", route->id_route);
	print_nodes(route->rooms);
}
