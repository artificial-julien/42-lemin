/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:50:33 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/28 14:56:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Free group's elements.
*/

void	group_free(void *content, size_t size)
{
	t_group	*group;
	int		i;

	(void)size;
	group = (t_group*)content;
	i = 0;
	while (i < group->route_count)
	{
		route_free(group->routes[i], sizeof(t_route));
		i++;
	}
	free(group->routes);
	free(group);
}

/*
**	Debug : Print a group and his routes.
*/

void	group_print(t_group *group)
{
	int	i;

#if DEBUG

	ft_fprintf(2, "Group (routes=%d; total_rounds=%d):\n", group->route_count, group->total_rounds);
#endif

	i = 0;
	while (i < group->route_count)
	{
		route_print(group->routes[i]);
		i++;
	}
}
