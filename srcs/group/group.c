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
	if (route != NULL)
	{
		ft_glstinsert(&group->routes,
			ft_glstnew(route, sizeof(route)), &route_cmp);
		group->count++;
		if (group->low_len == 0 || group->low_len > route->len)
			group->low_len = route->len;
		if (group->high_len == 0 || group->high_len < route->len)
			group->high_len = route->len;
	}
}

/*
** Function for testing the conflict between the routes of the group
** and one unique route
*/

t_bool	group_has_conflict_with(t_group *group, t_route *route)
{
	t_glist *lst;
	t_route *route_a;

	lst = group->routes;
	if (group_has_route(group, route))
		return (true);
	while (lst != NULL)
	{
		route_a = lst->route;
		if (route_has_conflict(route_a, route))
			return (true);
		lst = lst->next;
	}
	return (false);
}

/*
** Function for creating a group
** without conflit between one route and the list of routes
*/

void	group_route_conflict(t_glist **groups, t_route *a, t_glist *routes,
	t_lem_in *lem_in)
{
	t_glist *curr_routes;
	t_route *curr;
	t_group *group;

	group = group_new();
	curr_routes = routes;
	group_add_route(group, a);
	while ((curr_routes) && (curr = curr_routes->route)
		&& group->count < lem_in->nb_lem_algo)
	{
		if (!group_has_conflict_with(group, curr))
			group_add_route(group, curr);
		curr_routes = curr_routes->next;
	}
	if (!groups_has_duplicate(*groups, group))
	{
		groups_add(groups, group);
		group_print(group);
	}
	else
		group_free(group, sizeof(t_group));
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
