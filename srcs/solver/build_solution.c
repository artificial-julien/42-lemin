/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 14:55:55 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


/*
**	Move all ants of one route of the group.
*/

static void	ants_of_node_route(t_solution *solution, t_lem_in *lem_in, t_route *route)
{
	t_glist *curr;
	t_room *room_a;
	t_room *room_b;

	curr = route->rooms;
	while(curr->room != lem_in->start)
	{
		room_a = curr->room;
		room_b = curr->next->room;
		if (curr->room->type != end)
			move_ants(&room_b, &room_a, solution);
		if (room_b->type == start)
			break ;
		ft_printf(" ");
		curr = curr->next;
	}
}

/*
** test if all the group's route ofr moving ants.
*/

static void	ants_of_node(t_solution *solution, t_group *group, t_lem_in *lem_in)
{
	t_glist *curr;

	curr = group->routes;
	while(curr != NULL)
	{
		ants_of_node_route(solution, lem_in, curr->route);
		curr = curr->next;
	}
}

/*
**	Builds a solution or a set of moves using the specified group.
*/

void		build_solution(t_solution *solution, t_group *group, t_lem_in *lem_in)
{
	int ants_left;

	while ((lem_in->start->ants) >= 0
		&& lem_in->start->ants != lem_in->total_ants)
	{
		ants_left = lem_in->total_ants - lem_in->end->ants;
		ants_of_node(solution, group, lem_in);
		solution_add_round(solution);
	}
}
