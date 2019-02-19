/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/19 16:40:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Creates a new group of routes using the outgoing connections from the
**	start node.
*/

t_group	*group_build(t_room *start)
{
	t_group	*res;
	t_glist	*curr;
	t_route	*route;

	res = group_new();
	curr = start->links;
	while (curr != NULL)
	{
		if (curr->room->next != NULL || curr->room->type == end)
		{
			route = route_build(start, curr->room);
			group_add_route(res, route);
		}
		curr = curr->next;
	}
	return (res);
}

/*
**	Creates a new empty group.
*/

t_group	*group_new(void)
{
	t_group	*res;

	res = ft_memalloc(sizeof(t_group));
	return (res);
}

/*
**	Adds a route to the specified group.
*/

void	group_add_route(t_group *group, t_route *route)
{
	t_glist	*new;

	new = ft_glstnew(route, sizeof(t_route));
	ft_glstadd(&group->routes, new);
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

void	group_print(t_group *group)
{
	t_glist	*curr;

	ft_printf("Group:\n");
	curr = group->routes;
	while (curr != NULL)
	{
		route_print(curr->route);
		curr = curr->next;
	}
}
