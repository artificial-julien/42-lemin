/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:48:14 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 17:17:32 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ROOMS_COUNT 3
#define MOVES_COUNT 3

void	dummy_solution(t_lem_in *lem_in, t_solution *solution)
{
	// debug
	t_move	moves[MOVES_COUNT];
	t_room	*rooms[ROOMS_COUNT];
	int	i;

	rooms[0] = room_new("0", start, 0, 0);
	rooms[1] = room_new("1", standard, 0, 0);
	rooms[2] = room_new("2", end, 0, 0);
	moves[0].origin = rooms[0];
	moves[0].target = rooms[1];
	moves[1].origin = rooms[1];
	moves[1].target = rooms[2];
	moves[2].origin = rooms[2];
	moves[2].target = rooms[0];

	i = 0;
	while (i < ROOMS_COUNT)
	{
		lem_in_add_room(lem_in, rooms[i]);
		i++;
	}
	solution_add_round(solution);
	i = 0;
	while (i < MOVES_COUNT)
	{
		solution_add_move(solution, &moves[i]);
		i++;
	}
	solution_add_round(solution);
	moves[1].origin = rooms[2];
	moves[1].target = rooms[1];
	i = 0;
	while (i < MOVES_COUNT)
	{
		solution_add_move(solution, &moves[i]);
		i++;
	}
}

int			main(void)
{
	t_lem_in	lem_in;
	t_solution	solution;

	lem_in_init(&lem_in);
	solution.rounds = NULL;
	dummy_solution(&lem_in, &solution);
	solution_print(&solution);
	lem_in_free(&lem_in);
	return (0);
}
