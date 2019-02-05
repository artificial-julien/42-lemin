/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 14:31:47 by agoulas          ###   ########.fr       */
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

	routes = NULL;
	groups = NULL;
	create_nodes_weights(lem_in);
	//create_routes(lem_in, &routes);
	build_groups(&groups, routes);
	best_group = select_best_group(groups);
	build_solution(solution, best_group);
	ft_glstdel(&routes, route_free);
	ft_glstdel(&groups, group_free);
}
