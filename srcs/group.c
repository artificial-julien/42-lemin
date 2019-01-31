/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/31 19:57:28 by juazouz          ###   ########.fr       */
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

void	group_add_route(t_group *group, t_route *route)
{
	ft_glstadd(&group->routes, ft_glstnew(route, sizeof(route)));
	group->count++;
	if (group->low_len > route->len || group->low_len == 0)
		group->low_len = route->len;
	if (group->high_len < route->len || group->high_len == 0)
		group->high_len = route->len;
}

/*
** Function for creating a group
** without conflit between one route and the list of routes
*/

void	group_route_conflict(t_glist **groups, t_glist *routes, t_route *p)
{
	t_glist		*curr;
	t_route		*route_a;
	t_group		*group;

	curr = routes;
	route_a = (curr)->route;
	group = group_new();
	group_add_route(group, p);
	while (route_a != NULL)
	{
		if (route_cmp_conflit(*p, route_a) == 0)
			group_add_route(&group, route_a);
		curr = curr->next;
		route_a = (curr)->content;
	}
	groups_add_group(groups, &group);
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
