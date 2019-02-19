/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 18:20:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Core problem solving function.
**	Selects the best group and prints the solution.
*/

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
	routes = create_routes(lem_in);
	create_groups(&groups, routes, lem_in);
	best_group = select_best_group(groups, lem_in->total_ants);
	if (lem_in->opt.print_groups == true || lem_in->opt.debug == true)
		group_print(best_group);
	print_debug(lem_in, best_group, lem_in->opt.debug);
	build_solution(lem_in, best_group, solution);
	ft_glstdel(&routes, route_free);
	ft_glstdel(&groups, group_free);
}
