/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:33:38 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/15 18:24:10 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_round(t_lem_in lem_in, t_round *round)
{
	t_dlist		*curr;
	t_move		*move;

	curr = ft_dlstfirst(round->moves);
	while (curr != NULL)
	{
		move = (t_move*)curr->content;
		if (lem_in.opt.print_route == true)
			ft_printf("R%d:L%d-%s", move->id_route, move->ant_id,
				move->dst->name);
		else
			ft_printf("L%d-%s", move->ant_id, move->dst->name);
		if ((curr = curr->prev) != NULL)
			ft_putchar(' ');
	}
	ft_putendl("");
}

void		solution_print(t_lem_in lem_in, t_solution *solution)
{
	t_dlist	*curr;

	curr = ft_dlstfirst(solution->rounds);
	while (curr != NULL)
	{
		print_round(lem_in, (t_round*)curr->content);
		curr = curr->prev;
	}
	if (lem_in.opt.print_nblines == true)
		ft_printf("#-> Number of line written :%d \n",solution->round);
}
