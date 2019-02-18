/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/18 20:39:34 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Updates the nodes connections (prev, next) representing the routes on
**	the map.
**	after a Edmonds-Karp traverse.
*/

static void	rebuild_routes(t_route *route, t_room *start)
{
	t_glist	*curr;
	t_room	*prev;

	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		if (curr->room->prev == NULL)
		{
			curr->room->prev = prev;
			if (prev != NULL)
				prev->next = curr->room;
		}
		else
		{
			curr->room->next = NULL;
			curr->room->prev = NULL;
		}
		prev = curr->room;
		curr = curr->next;
	}
}

static void	create_groups(t_room *start, t_glist **groups)
{
	t_bft	*bft;

	while ((bft = bft_run(start)) != NULL)
	{
		rebuild_routes(bft->route, start);
		group = group_build(start);
		bft_free(bft);
	}
}

/*
**	Core problem solving function.
**	Selects the best group and prints the solution.
*/

static void	print_debug(t_lem_in *lem_in, t_group *best_group, t_bool debug)
{
	if (debug == true)
	{
		ft_printf("Rounds for group:\nRounds:\t%d\nAnts:\t%d\n",
			group_total_rounds(best_group, lem_in->total_ants),
			lem_in->total_ants);
		group_print(best_group);
	}
}

/*
**	Core problem solving function.
**	Selects the best group and prints the solution.
*/

void		solve(t_lem_in *lem_in, t_solution *solution)
{
	t_glist		*routes;
	t_glist		*groups;
	t_group		*best_group;

	groups = NULL;
	create_groups(lem_in->start, &groups);
	best_group = select_best_group(groups, lem_in->total_ants);
	print_debug(lem_in, best_group, false);
	build_solution(lem_in, best_group, solution);
	ft_glstdel(&routes, route_free);
	ft_glstdel(&groups, group_free);
}
