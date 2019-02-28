/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:19:01 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 19:45:13 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	min(int a, int b)
{
	return (a > b ? b : a);
}

/*
**	Returns the number of max possible routes.
**	Matches the minimum among of outgoing routes from the start and end nodes
**	and the number of ants.
*/

int		max_routes(t_lem_in *lem_in)
{
	int	res;
	int	start;
	int	end;

	start = lem_in->start->links_count;
	end = lem_in->end->links_count;
	res = min(start, end);
	res = min(res, lem_in->total_ants);
	return (res);
}

static void	build_distances(t_room *room)
{
	int		i;
	t_room	*curr;

	curr = room;
	i = 1;
	while (curr->type != start)
	{
		curr->distance = i;
		i++;
		curr = curr->prev;
	}
}

/*
**	Fills the room of the existant routes with distance from end.
*/

void	build_routes_distances(t_lem_in *lem_in)
{
	t_glist	*curr;

	curr = lem_in->end->links;
	while (curr != NULL)
	{
		if (curr->room->prev != NULL)
			build_distances(curr->room);
		curr = curr->next;
	}
}
