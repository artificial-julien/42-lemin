/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 19:27:06 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/31 13:07:47 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft"

void	del_route_group_conflict(t_group **g, t_list **routes, t_route *p)
{
	t_route  *tmp;

	tmp = routes;
	groupe_add_route(g, p)
	while (tmp != NULL)
	{
		if (route_cmp_conflit(p, tmp->content) == 0)
			group_add_route(g, tmp->content);
		tmp = tmp->next;
	}
}

void	try_route(t_list **groups, t_list **routes)
{
	t_route *index_route;

	index_route = *route;
	while (index_route != NULL)
	{

	}
}

void»···build_groups(t_list **groups, t_list **routes)
{

}
