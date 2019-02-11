/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/11 17:13:20 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

/*
** Move the ants forn a room to another and print the move.
*/

void	ant_move(t_room **src, t_room **dest, t_solution *solution)
{
	if ((*src)->ants > 0 && (ant_can_move((*dest)) == 1))
	{
		(*src)->ants--;
		(*dest)->ants++;
		ft_printf("L%s%d%s ", (*src)->name, solution->round, (*dest)->name);
	}
}

/*
**	Function testing the links for if the next room is empty
*/

t_bool	ant_can_move(t_room *room)
{
	if ((room->ants == 0 && room->type == standard) || (room->type == end))
		return (1);
	return (0);
}
