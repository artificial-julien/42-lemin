/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 17:50:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/26 13:52:42 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Move the ants forn a room to another and print the move.
*/

t_bool	ant_try_move(t_room *src, t_room *dest, t_solution *solution)
{
	if (src->ants > 0 && ant_can_move(dest))
	{
		src->ants--;
		dest->ants++;
		dest->ant_id = src->ant_id;
		if (src->type == start)
		{
			src->ant_id++;
			dest->ant_id = src->ant_id;
		}
		solution_add_move(solution, dest);
		return (true);
	}
	return (false);
}

/*
**	Function testing the links for if the next room is empty
*/

t_bool	ant_can_move(t_room *room)
{
	if ((room->ants == 0 && room->type == standard) || (room->type == end))
		return (true);
	return (false);
}

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
**	Executes one round of the solution. Prints one line.
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
	while ((lem_in->start->ants) >= 0
		&& lem_in->end->ants != lem_in->total_ants)
	{
		run_round(group, lem_in, solution);
	}
}
