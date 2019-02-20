/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_create_conflict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/04 16:25:47 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		if (lem_in->opt.print_groups == true || lem_in->opt.debug == true)
			group_print(group);
	}
	else
		group_free(group, sizeof(t_group));
}
