/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:27:06 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/31 17:24:27 by agoulas          ###   ########.fr       */
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

void	build_groups(t_glist **groups, t_glist **routes)
{
	t_glist *index_route;

	index_route = *routes;
	while (index_route != NULL)
	{
		group_route_conflict(groups, routes, index_route->content);
		index_route = index_route->next;
	}
}

/*
**	Function to retest the group and concatene les group 
**	et limiting the number of group
*/

void	groups_organise(t_glist **groups, t_glist **routes)
{
	(void)groups;
	(void)routes;
}
