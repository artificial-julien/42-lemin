/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/30 16:57:52 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function testing the links for if the next room is empty
*/

t_bool		ants_cam_move(t_list *links)
{
	t_room *r;

	r = *((t_room**)links->content);
	if ((r->ants == 0 && r->type == standard) || (r->type == end))
		return (1);
	return (0);
}

/*
** Function of resolution of the programme
*/

void	solve(t_lem_in *lem_in, t_solution *solution)
{
	ft_printf("test solve\n");
	return ;
	while (lem_in->end->ants != lem_in->total_ants)
	{
		solution_add_round(solution);

	}
}
