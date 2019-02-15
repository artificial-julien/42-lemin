/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 17:56:10 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int ac, char **av)
{
	t_lem_in	lem_in;
	t_solution	solution;

	lem_in_init(&lem_in);
	parse_opt(&lem_in, ac, av);
	parse(&lem_in);
	lem_in.nb_lem_algo = 3;
	solution_init(&solution);
	ft_printf("/**********/\n lnb_route by group = %d\n**********************/\n",lem_in.nb_lem_algo);
	solve(&lem_in, &solution);
	solution_print(&solution);
	lem_in_free(&lem_in);
	return (0);
}
