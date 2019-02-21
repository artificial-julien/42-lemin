/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/21 13:27:51 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	If debug option is on
**	Prints the specified newly created group.
*/

static void	debug_print_new_group(t_lem_in *lem_in, t_group *group)
{
	if (lem_in->opt.debug == true)
	{
		ft_fprintf(2, "Created group :\n");
		group_print(group);
	}
}

/*
**	If debug option is on
**	Prints the specified newly created virtual route.
*/

static void	debug_print_new_route(t_lem_in *lem_in, t_route *virtual_route)
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

static void	create_groups(t_lem_in *lem_in, t_glist **groups, int rooms_count)
{
	t_bft	*initial_bft;
	t_bft	*bft;
	t_group	*group;
	t_glist	*new;

	initial_bft = bft_new(rooms_count);
	bft_add_node(initial_bft, lem_in->start);
	while ((bft = bft_run(lem_in, initial_bft)) != NULL)
	{
		ft_glstrev(&bft->virtual_route->rooms);
		rebuild_routes(bft->virtual_route);
		debug_print_new_route(lem_in, bft->virtual_route);
		group = group_build(lem_in->start);
		debug_print_new_group(lem_in, group);
		new = ft_glstnew(group, sizeof(t_group));
		ft_glstadd(groups, new);
		bft_free(bft, sizeof(t_bft));
	}
}

/*
**	If debug option is on
**	Prints the number of round for each group for a number of ants given.
*/

static void	debug_print_rounds_info(t_lem_in *lem_in, t_group *best_group)
{
	if (lem_in->opt.debug == true)
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
	t_glist		*groups;
	t_group		*best_group;

	groups = NULL;
	create_groups(lem_in, &groups, ft_glstlen(lem_in->rooms));
	best_group = select_best_group(groups, lem_in->total_ants);
	debug_print_rounds_info(lem_in, best_group);
	build_solution(lem_in, best_group, solution);
	ft_glstdel(&groups, group_free);
}
