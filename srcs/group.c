/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/31 17:09:03 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function of initialisation of a new group_creat
*/

void	group_creat(t_group **g)
{
	(*g) = malloc(sizeof(t_group*));
	(*g)->count = 0;
	(*g)->high_len = 0;
	(*g)->low_len = 0;
}

/*
** Function that add a route to a group
** and actualize the information of the group
*/

void	group_add_route(t_group **group, t_route *route)
{
	ft_lstadd(&(*group)->routes, ft_lstnew(route, sizeof(route)));
	(*group)->count++;
	if ((*group)->low_len > route->len || (*group)->low_len == 0)
		(*group)->low_len = route->len;
	if ((*group)->high_len < route->len || (*group)->high_len == 0)
		(*group)->high_len = route->len;
}

/*
** Function for creating a group
** without conflit between one route and the list of routes
*/

void	group_route_conflict(t_list **groups, t_list **routes, t_route **p)
{
	t_list		*lst;
	t_route		*route_a;
	t_group		*group;

	lst = *routes;
	route_a = (lst)->content;
	group_creat(&group);
	group_add_route(&group, *p);
	while (route_a != NULL)
	{
		if (route_cmp_conflit(*p, route_a) == 0)
			group_add_route(&group, route_a);
		lst = lst->next;
		route_a = (lst)->content;
	}
	groups_add_group(groups, &group);
}

/*
**	Function for freeing a group from the list of groups
*/

void	group_del_lst(t_list **group, t_group *group)
{
	t_list *lst;

	lst = groups;
	if (groups && group)
	{
		if (lst->content == groups)
	}
}
