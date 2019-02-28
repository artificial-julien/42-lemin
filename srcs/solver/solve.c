/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 15:48:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	If debug option is on
**	Prints the specified newly created group.
*/

static void		debug_print_new_group(t_lem_in *lem_in, t_group *group)
{
	if (lem_in->opt.debug || lem_in->opt.print_groups)
	{
		ft_fprintf(2, "Created group :\n");
		group_print(group);
	}
}

/*
**	If debug option is on
**	Prints the specified newly created virtual route.
*/

static void		debug_print_new_route(t_lem_in *lem_in, t_route *virtual_route)
{
	if (lem_in->opt.debug == true)
	{
		ft_putendl_fd("=========================================", 2);
		ft_fprintf(2, "Created virtual route :\n");
		route_print(virtual_route);
	}
}

/*
**	Runs the Edmonds-Karp traverse as many time as possible and records a group
**	of routes every time.
*/

static t_group	*create_best_group(t_lem_in *lem_in)
{
	t_bft	*initial_bft;
	t_bft	*bft;
	t_group	*prev_group;
	t_group	*group;
	int		count;

	initial_bft = bft_new(lem_in->room_len);
	bft_add_node(initial_bft, lem_in->start);
	count = 0;
	prev_group = NULL;
	while (count < lem_in->max_routes
		&& (bft = bft_run(lem_in, initial_bft)) != NULL)
	{
		ft_glstrev(&bft->virtual_route->rooms);
		rebuild_routes(bft->virtual_route);
		debug_print_new_route(lem_in, bft->virtual_route);
		group = group_build(lem_in);
		debug_print_new_group(lem_in, group);
		bft_free(bft, sizeof(t_bft));
		if (prev_group != NULL
			&& prev_group->total_rounds < group->total_rounds)
		{
			group_free(group, sizeof(t_group));
			return (prev_group);
		}
		if (prev_group != NULL)
			group_free(prev_group, sizeof(t_group));
		prev_group = group;
		count++;
	}
	return (group);
}

/*
**	If debug option is on
**	Prints the number of round for each group for a number of ants given.
*/

static void		debug_print_rounds_info(t_lem_in *lem_in, t_group *best_group)
{
	if (lem_in->opt.debug == true)
	{
		ft_fprintf(2, "Rounds for group:\nRounds:\t%d\nAnts:\t%d\n",
			best_group->total_rounds,
			lem_in->total_ants);
		group_print(best_group);
	}
}

/*
**	Core problem solving function.
**	Selects the best group and prints the solution.
*/

void			solve(t_lem_in *lem_in, t_solution *solution)
{
	t_group		*best_group;

	lem_in->max_routes = max_routes(lem_in);
	best_group = create_best_group(lem_in);
	if (best_group == NULL)
		lem_in_die();
	debug_print_rounds_info(lem_in, best_group);
	build_solution(lem_in, best_group, solution);
}
