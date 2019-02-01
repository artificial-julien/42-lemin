/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:27:06 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/01 16:29:07 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function to test is group_a is equal to group_b
*/

t_bool	groups_equals(t_group *group_a, t_group *group_b)
{
	t_glist *routes_a;
	t_glist *routes_b;

	if (group_a->count == group_b->count
		&& group_a->high_len == group_b->high_len
		&& group_a->low_len == group_b->low_len)
	{
		routes_a = group_a->routes;
		routes_b = group_b->routes;
		if (routes_equals(routes_a, routes_b) == group_a->count)
			return (1);
		return (0);
	}
	else
		return (false);
}

/*
** Function testing if "group" has a doublon in the list
*/

t_bool	groups_doublon_group(t_glist *groups, t_group *group)
{
	t_glist *groups_b;

	groups_b = groups;
	if (groups_b)
	{
		if (groups_equals(group, groups_b->content) == 1)
			return (true);
		groups_b = groups_b->next;
	}
	return (false);
}

/*
**	Function to add a group to the list of groups
*/

void	groups_add_group(t_glist **groups, t_group *group)
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
		group_route_conflict(groups, (curr_route)->route, routes);
		curr_route = curr_route->next;
	}
}
