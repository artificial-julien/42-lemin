/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:38:13 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 17:30:02 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	rounds_for_route(t_group *group, int index)
{
	if (group->ants_distribution[index] == 0)
		return (0);
	return (group->routes[index]->len + group->ants_distribution[index] - 1);
}

static void	distribute_one(t_group *group)
{
	int	i;

	i = 0;
	while (i < group->route_count - 1
		&& rounds_for_route(group, i) > rounds_for_route(group, i + 1))
	{
		i++;
	}
	group->ants_distribution[i]++;
}

/*
**	Stores and array of the number of ants to move in to routes.
*/

void		distribute_ants(t_group *group, int total_ants)
{
	int	left_ants;

	left_ants = total_ants;
	while (left_ants > 0)
	{
		distribute_one(group);
		left_ants--;
	}
}
