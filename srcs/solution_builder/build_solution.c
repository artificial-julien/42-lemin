/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 18:22:41 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Move all ants of one route of the group.
*/

static void	run_route(t_lem_in *lem_in, t_route *route, t_solution *solution)
{
	t_glist	*curr;
	t_room	*room_a;
	t_room	*room_b;

	curr = route->rooms;
	while (curr->room != lem_in->start)
	{
		room_a = curr->room;
		room_b = curr->next->room;
		ant_try_move(room_b, room_a, solution);
		curr = curr->next;
	}
}

/*
** test if all the group's route ofr moving ants.
*/

static void	run_round(t_group *group, t_lem_in *lem_in, t_solution *solution)
{
	t_glist *curr;

	solution_add_round(solution);
	curr = group->routes;
	while (curr != NULL)
	{
		run_route(lem_in, curr->route, solution);
		curr = curr->next;
	}
}

/*
**	Builds a solution or a set of moves using the specified group.
*/

void		build_solution(t_lem_in *lem_in, t_group *group,
	t_solution *solution)
{
	int ants_left;

	while ((lem_in->start->ants) >= 0
		&& lem_in->end->ants != lem_in->total_ants)
	{
		ants_left = lem_in->total_ants - lem_in->end->ants;
		run_round(group, lem_in, solution);
	}
}
