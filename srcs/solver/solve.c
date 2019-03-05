/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 19:21:23 by juazouz          ###   ########.fr       */
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
**	Resets the visited flags and the routes.
*/

static void		reset_visited(t_lem_in *lem_in)
{
	t_glist	*curr;

	curr = lem_in->rooms;
	while (curr != NULL)
	{
		curr->room->visited = false;
		curr = curr->next;
	}
}

/*
**	Runs the Edmonds-Karp traverse as many time as possible and records a group
**	of routes every time.
*/

static t_group	*create_best_group(t_lem_in *lem_in)
{
	t_group			*best_group;
	t_group			*group;
	int				count;
	t_route			*virtual_route;

	count = 0;
	best_group = NULL;
	while (count < lem_in->max_routes
		&& (virtual_route = run_bft(lem_in)) != NULL)
	{
		reset_visited(lem_in);
		rebuild_routes(lem_in, virtual_route);
		debug_print_new_route(lem_in, virtual_route);
		group = group_build(lem_in);
		debug_print_new_group(lem_in, group);
		if (best_group == NULL)
			best_group = group;
		else if (best_group->total_rounds > group->total_rounds)
		{
			group_free(best_group, sizeof(t_group));
			best_group = group;
		}
		else
		{
			group_free(group, sizeof(t_group));
		}
		count++;
	}
	return (best_group);
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
