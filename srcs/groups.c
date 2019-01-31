/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:27:06 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/31 19:23:32 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function to add a group to the list of groups
*/

void	groups_add_group(t_glist **groups, t_group **group)
{
	if (groups && group)
		ft_glstadd(groups, ft_glstnew(group, sizeof(group)));
}

/*
**	Function to create all groups  from the list of routes
*/

void	build_groups(t_glist **groups, t_glist *routes)
{
	t_glist *curr_route;

	curr_route = routes;
	while (curr_route != NULL)
	{
		group_route_conflict(groups, routes, curr_route->route);
		curr_route = curr_route->next;
	}
}

/*
**	Function to retest the group and concatene les group
**	et limiting the number of group
*/

void	group_organise(t_group **group)
{
	t_glist		*curr_routes;
	t_glist		*ind_route;
	t_route		tmp;


	curr_routes = (*group)->routes;
	while (curr_routes != NULL
			&& curr_routes->id_route != (*group)->id)
	{
		tmp = curr_routes->route;
		ind_route = (*group)->routes;
		while (ind_route != NULL && ind_route->next != NULL)
		{
			if (route_cmp_conflit(tmp, ind_route->route) == 0)

			ind_route = ind_route->next;
		}
		curr_routes = curr_routes->next;
	}
}
