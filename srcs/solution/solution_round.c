/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_round.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:37:23 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/06 17:40:12 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
**	Free the round.
*/

void		round_free(void *content, size_t size)
{
	t_round	*round;

	(void)size;
	round = (t_round*)content;
	ft_dlstdel(&round->moves, NULL);
}
