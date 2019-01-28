/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:24:30 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/28 18:31:56 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_round(t_round *round)
{
	t_list	*curr;
	t_move	*move;

	curr = round->moves;
	while (curr != NULL)
	{
		move = (t_move*)curr;
		ft_printf("L%s-%s", move->origin->name, move->target->name);
		curr = curr->next;
		if (curr != NULL)
			ft_putchar(" ");
	}
	ft_putendl("");
}

void		print_solution(t_solution *solution)
{
	t_list	*curr;

	curr = solution->rounds;
	while (curr != NULL)
	{
		print_round((t_round*)curr);
		curr = curr->next;
	}
}
