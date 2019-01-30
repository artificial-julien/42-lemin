/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/30 19:21:39 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Core problem solving function.
*/

void	solve(t_lem_in *lem_in, t_solution *solution)
{
	t_list		*routes;
	t_list		*groups;
	t_group		*best_group;

	routes = NULL;
	groups = NULL;
	scan_routes(lem_in, &routes);
	build_groups(&groups);
	best_group = select_best_group(groups);
	build_solution(solution);
	ft_lstdel(&routes, route_free);
	ft_lstdel(&groups, group_free);
}
