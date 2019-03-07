/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/07 14:43:14 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	t_lem_in	lem_in;
	t_solution	solution;

	lem_in_init(&lem_in);
	parse_opt(&lem_in, ac, av);
	if (lem_in.opt.print_help == true)
	{
		printf_help();
		return (0);
	}
	parse(&lem_in);
	solution_init(&solution);
	solve(&lem_in, &solution);
	print_display(&lem_in);
	solution_print(lem_in, &solution);
	solution_free(&solution);
	lem_in_free(&lem_in);
	return (0);
}
