/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_routes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 19:23:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 21:00:53 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	record_route(t_glist *nodes, t_glist **routes)
{
	t_glist			*new_lst;
	t_route			*new_route;
	static int		id_route;

	new_route = route_new();
	new_route->rooms = ft_glstcpy(nodes);
	new_route->id_route = id_route;
	id_route++;
	new_lst = ft_glstnew(new_route, sizeof(t_route));
	ft_glstadd(routes, new_lst);
	route_print(new_route);
}

/*
**	Returns the list of all the possible routes of the graph.
*/

static void	create_routes_core(t_room *node, t_glist **nodes, t_glist **routes)
{
	t_glist			*curr;
	t_glist			*new_node;

	new_node = ft_glstnew(node, sizeof(t_room));
	ft_glstadd(nodes, new_node);
	if (node->type == end)
	{
		record_route(*nodes, routes);
	}
	else
	{
		curr = node->links;
		while (curr != NULL)
		{
			if (curr->room->type != start
				&& !ft_glsthascontent(*nodes, curr->room))
			{
				create_routes_core(curr->room, nodes, routes);
			}
			curr = curr->next;
		}
	}
	ft_glstdelone(nodes, NULL);
}

t_glist		*create_routes(t_lem_in *lem_in)
{
	t_glist	*routes;
	t_glist	*nodes;

	routes = NULL;
	nodes = NULL;
	create_routes_core(lem_in->start, &nodes, &routes);
	return (routes);
}
