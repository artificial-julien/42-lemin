/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/01 18:27:28 by juazouz          ###   ########.fr       */
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
	return (res);
}

/*
** Function that add a route to a group
** and actualize the information of the group
*/

void	group_add_route(t_group **group, t_route *route)
{
	ft_glstadd(&(*group)->routes, ft_glstnew(route, sizeof(route)));
	(*group)->count++;
	if ((*group)->low_len > route->len || (*group)->low_len == 0)
		(*group)->low_len = route->len;
	if ((*group)->high_len < route->len || (*group)->high_len == 0)
		(*group)->high_len = route->len;
}

/*
** Function for testing the conflict between the routes of the group
** and one unique route
*/

t_bool	group_has_conflict(t_group **group, t_route *route)
{
	t_glist *lst;
	t_route *route_a;

	lst = (*group)->routes;
	while (lst != NULL)
	{
		route_a = lst->content;
		if (route_has_conflict(route_a, route) == true)
			return (true);
		lst = lst->next;
	}
	return (false);
}

/*
** Function for creating a group
** without conflit between one route and the list of routes
*/

void	group_route_conflict(t_glist **groups, t_route *a, t_glist *routes)
{
	t_glist *routes_cpy;
	t_route *curr;
	t_group *group;

	group = group_new();
	routes_cpy = routes;
	while (routes_cpy != NULL)
	{
		curr = routes->route;
		if (route_has_conflict(curr, a) == false
				&& group_has_conflict(&group, curr) == false)
			group_add_route(&group, curr);
		routes_cpy = routes_cpy->next;
	}
	groups_add_group(groups, group);
}

/*
**	Function for freeing a group from the list of groups
*/

void	group_del_lst(t_glist **groups, t_group *group)
{
	t_glist *lst;

	lst = *groups;
	if (groups && group)
	{
		//if (lst->content == groups)
	}
}

/*
**	Returns true if both groups are identical.
*/

t_bool	group_equals(t_group *group_a, t_group *group_b)
{
	t_glist *route_a;
	t_glist *route_b;

	if (group_a->count == group_b->count
		&& group_a->high_len == group_b->high_len
		&& group_a->low_len == group_b->low_len)
	{
		route_a = group_a->routes;
		route_b = group_b->routes;
		// Julien: A mon avis, on a juste besoin de comparer les pointeurs,
		// pas le contenu.
		// Et que vient faire "== group_a->count" ici ?
		// if (route_equals(route_a->route, route_b->route) == group_a->count)
		// 	return (1);
		if (route_a->route == route_b->route)
			return (1);
		return (0);
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
