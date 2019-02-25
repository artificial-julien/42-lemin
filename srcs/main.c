/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/25 17:47:03 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	t_lem_in	lem_in;
	t_solution	solution;

	g_glstpool = mempool_new(1024 * 256 * 256, sizeof(t_glist));
	lem_in_init(&lem_in);
	parse_opt(&lem_in, ac, av);
	if (lem_in.opt.print_help == true)
	{
		printf_help();
		return (0);
	}
	time_profiling(&lem_in, true, NULL);
	parse(&lem_in);
	solution_init(&solution);
	solve(&lem_in, &solution);
	time_profiling(&lem_in, false, "Solving");
	print_lines(&lem_in);
	solution_print(&solution);
	time_profiling(&lem_in, false, "Writing result");
	lem_in_free(&lem_in);
	free(g_glstpool);
	return (0);
}
