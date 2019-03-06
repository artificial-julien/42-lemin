/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:24:30 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 17:40:31 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		solution_init(t_solution *solution)
{
	solution->round = 0;
	solution->rounds = NULL;
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

/*
** Free the dlist solution.
*/

void		solution_free(t_solution *solution)
{
	ft_dlstdel(&solution->rounds, round_free);
}
