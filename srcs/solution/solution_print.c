/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:33:38 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/21 18:52:13 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_round(t_round *round)
{
	t_dlist		*curr;
	t_move		*move;
	static int	last_ant_id;
	int			ant_id;

	curr = ft_dlstfirst(round->moves);
	while (curr != NULL)
	{
		move = (t_move*)curr->content;
		if (move->src->type == start)
		{
			last_ant_id++;
			ant_id = last_ant_id;
		}
		else
		{
			ant_id = move->src->ant_id;
		}
		ft_printf("L%d-%s", ant_id, move->dst->name);
		move->dst->ant_id = ant_id;
		move->src->ant_id = 0;
		curr = curr->prev;
		if (curr != NULL)
			ft_putchar(' ');
	}
	ft_putendl("");
}

void		solution_print(t_solution *solution)
{
	t_dlist	*curr;

	curr = ft_dlstfirst(solution->rounds);
	while (curr != NULL)
	{
		print_round((t_round*)curr->content);
		curr = curr->prev;
	}
}
