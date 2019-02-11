/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 17:07:49 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Core problem solving function.
*/

void	solve(t_lem_in *lem_in, t_solution *solution)
{
	t_glist		*routes;
	t_glist		*groups;
	t_group		*best_group;

	groups = NULL;
	routes = create_routes(lem_in);
	create_groups(&groups, routes, lem_in);
	best_group = select_best_group(groups, lem_in->total_ants);
#if DEBUG
	ft_printf("Rounds for group:\nRounds:\t%d\nAnts:\t%d\n",
				group_total_rounds(best_group, lem_in->total_ants),
				lem_in->total_ants);
	group_print(best_group);
#endif
	// sort_routes(best_group);
	build_solution(solution, best_group, lem_in);
	ft_glstdel(&routes, route_free);
	ft_glstdel(&groups, group_free);
}
