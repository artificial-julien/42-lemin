/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:41:57 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 15:19:06 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_lem_in	lem_in;
	t_solution	solution;

	lem_in_init(&lem_in);
	parse(&lem_in);
	solve(&lem_in, &solution);
	solution_print(&solution);
	lem_in_free(&lem_in);
	return (0);
}
