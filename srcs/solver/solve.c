/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/20 13:10:18 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Updates the nodes connections (prev, next) representing the routes on
**	the map using the virtual route created by the Edmonds-Karp traverse.
*/

static void	rebuild_routes(t_route *route)
{
	t_glist	*curr;
	t_room	*prev;

	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		if (curr->room->type == start)
		{
		}
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

static void	create_groups(t_room *start, t_glist **groups, int rooms_count)
{
	t_bft	*initial_bft;
	t_bft	*bft;
	t_group	*group;
	t_glist	*new;

	initial_bft = bft_new(rooms_count);
	bft_add_node(initial_bft, start);
	while ((bft = bft_run(initial_bft)) != NULL)
	{
		ft_glstrev(&bft->virtual_route->rooms);
		rebuild_routes(bft->virtual_route);
#ifdef DEBUG

		ft_putendl_fd("=========================================", 2);
		ft_fprintf(2, "Created virtual route :\n");
		route_print(bft->virtual_route);
#endif

		group = group_build(start);
#ifdef DEBUG

		ft_fprintf(2, "Created group :\n");
		group_print(group);
#endif

		new = ft_glstnew(group, sizeof(t_group));
		ft_glstadd(groups, new);
		bft_free(bft, sizeof(t_bft));
	}
}

static void	print_debug(t_lem_in *lem_in, t_group *best_group, t_bool debug)
{
	if (debug == true)
	{
		ft_fprintf(2, "Rounds for group:\nRounds:\t%d\nAnts:\t%d\n",
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
	create_groups(lem_in->start, &groups, ft_glstlen(lem_in->rooms));
	best_group = select_best_group(groups, lem_in->total_ants);
	print_debug(lem_in, best_group, false);
	build_solution(lem_in, best_group, solution);
	ft_glstdel(&routes, route_free);
	ft_glstdel(&groups, group_free);
}
