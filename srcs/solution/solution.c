/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:24:30 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 16:07:48 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		solution_init(t_solution *solution)
{
	solution->round = 0;
	solution->rounds = NULL;
}

/*
**	Creates a new empty round.
*/

void		solution_add_round(t_solution *solution)
{
	t_round	*round;
	t_dlist	*new;

	round = ft_memalloc(sizeof(t_round));
	new = ft_dlstnew(round, sizeof(t_round));
	ft_dlstadd(&solution->rounds, new);
	solution->round++;
}

/*
**	Discards the latest round and its moves.
**	Liberates the round and moves memory.
*/

void		solution_discard_round(t_solution *solution)
{
	t_round	*round;
	t_dlist	*curr;

	curr = solution->rounds;
	if (curr == NULL)
		lem_in_die();
	round = (t_round*)curr->content;
	ft_dlstdel(&round->moves, NULL);
	ft_dlstdelone(&solution->rounds, NULL);
}

/*
**	Adds a move to the current round.
*/

void		solution_add_move(t_solution *solution, t_room *dst)
{
	t_round	*round;
	t_dlist	*new;
	t_move	*move;

	move = ft_memalloc(sizeof(t_move));
	move->id_route = solution->route;
	move->ant_id = dst->ant_id;
	move->dst = dst;
	new = ft_dlstnew(move, sizeof(t_move));
	round = (t_round*)solution->rounds->content;
	ft_dlstadd(&round->moves, new);
}

void		round_free(void *content, size_t size)
{
	t_round	*round;

	(void)size;
	round = (t_round*)content;
	ft_dlstdel(&round->moves, NULL);
}

void		solution_free(t_solution *solution)
{
	ft_dlstdel(&solution->rounds, round_free);
}
