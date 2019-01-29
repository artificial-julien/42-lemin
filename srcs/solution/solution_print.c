/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:33:38 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 14:50:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_round(t_round *round)
{
	t_dlist	*curr;
	t_move	*move;

	curr = ft_dlstfirst(round->moves);
	while (curr != NULL)
	{
		move = (t_move*)curr->content;
		ft_printf("L%s-%s", move->origin->name, move->target->name);
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
