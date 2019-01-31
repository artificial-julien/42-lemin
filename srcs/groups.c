/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:27:06 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/31 14:07:39 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function to add a group to the list of groups
*/

void	groups_add_group(t_list **groups, t_group **group)
{
	if (groups && group)
		ft_lstadd(groups, ft_lstnew(group, sizeof(group)));
}

/*
** function to create all groups  from the list of routes
*/

void	build_groups(t_list **groups, t_list **routes)
{
	t_list *index_route;

	index_route = *routes;
	while (index_route != NULL)
	{
		del_route_group_conflict(groups, routes, index_route->content);
		index_route = index_route->next;
	}
}
