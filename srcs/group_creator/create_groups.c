/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_groups.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:27:06 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/11 17:11:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function testing if "group" has a doublon in the list
*/

t_bool		groups_has_duplicate(t_glist *groups, t_group *group)
{
	t_glist *groups_b;

	groups_b = groups;
	while (groups_b)
	{
		if (group_equals(group, groups_b->content) == 1)
			return (true);
		groups_b = groups_b->next;
	}
	return (false);
}

/*
**	Function to add a group to the list of groups
*/

void		groups_add(t_glist **groups, t_group *group)
{
	ft_glstadd(groups, ft_glstnew(group, sizeof(group)));
}

/*
**	Function to create all groups  from the list of routes
*/

void		create_groups(t_glist **groups, t_glist *routes,
	t_lem_in *lem_in)
{
	t_glist	*curr;
	int		routes_count;

	routes_count = ft_glstlen(routes);
	curr = routes;
	while (curr != NULL)
	{
		route_create_conflicts_map(curr->route, routes, routes_count);
		curr = curr->next;
	}
	curr = routes;
	while (curr != NULL)
	{
		group_route_conflict(groups, (curr)->route, routes, lem_in);
		curr = curr->next;
	}
}
