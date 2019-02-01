/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/01 16:31:24 by agoulas          ###   ########.fr       */
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
