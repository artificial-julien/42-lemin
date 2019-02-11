/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:24:30 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 16:28:27 by juazouz          ###   ########.fr       */
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
	/*
	**
	*/
	solution->round++;
	ft_printf("\n");
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

void		solution_add_move(t_solution *solution, t_move *move)
{
	t_round	*round;
	t_dlist	*new;

	new = ft_dlstnew(move, sizeof(t_move));
	round = (t_round*)solution->rounds->content;
	ft_dlstadd(&round->moves, new);
}
