/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 19:47:09 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	If debug option is on
**	Prints the specified newly created virtual route.
*/

static void		debug_print_new_route(t_lem_in *lem_in, t_route *traverse)
{
	if (lem_in->opt.debug || lem_in->opt.print_groups)
	{
		ft_putendl_fd("=========================================", 2);
		ft_fprintf(2, "Created virtual route :\n");
		route_print(traverse);
	}
}

static void		debug_print_max_groups(t_lem_in *lem_in)
{
	if (lem_in->opt.print_groups)
	{
		ft_fprintf(2, "Max groups count: %d\n", lem_in->max_routes);
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
	t_route			*traverse;

	count = 0;
	best_group = NULL;
	while (count < lem_in->max_routes && (traverse = run_bft(lem_in)) != NULL)
	{
		debug_print_new_route(lem_in, traverse);
		rebuild_routes(lem_in, traverse);
		route_free(traverse, sizeof(t_route));
		group = group_build(lem_in);
		if (best_group == NULL)
			best_group = group;
		else if (best_group->total_rounds > group->total_rounds)
		{
			group_free(best_group, sizeof(t_group));
			best_group = group;
		}
		else
			group_free(group, sizeof(t_group));
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
	debug_print_max_groups(lem_in);
	best_group = create_best_group(lem_in);
	if (best_group == NULL || best_group->routes == NULL)
		lem_in_die();
	build_solution(lem_in, best_group, solution);
	group_free(best_group, sizeof(t_group));
}

