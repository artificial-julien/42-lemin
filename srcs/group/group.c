/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/18 20:24:39 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Creates a new group of routes using the outgoing connections from the
**	start node.
*/

t_group	*group_build(t_room *start)
{
	t_group	*res;

	res = group_new();

	return (res);
}

/*
** Function of initialisation of a new group_creat
*/

t_group	*group_new(void)
{
	t_group	*res;

	res = ft_memalloc(sizeof(t_group));
	res->count = 0;
	res->high_len = 0;
	res->low_len = 0;
	return (res);
}

/*
**	Free group's elements.
*/

void	group_free(void *content, size_t size)
{
	t_group	*group;

	(void)size;
	group = (t_group*)content;
	ft_glstdel(&group->routes, NULL);
	free(group);
}

void	group_print(t_group *group)
{
	t_glist	*curr;

	ft_printf("Group:\n");
	curr = group->routes;
	while (curr != NULL)
	{
		route_print(curr->route);
		curr = curr->next;
	}
}
