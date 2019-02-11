/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/11 18:18:55 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

/*
** Move the ants forn a room to another and print the move.
*/

t_bool	ant_try_move(t_room *src, t_room *dest, t_solution *solution)
{
	if (src->ants > 0 && ant_can_move(dest))
	{
		src->ants--;
		dest->ants++;
		solution_add_move(solution, src, dest);
		return (true);
	}
	return (false);
}

/*
**	Function testing the links for if the next room is empty
*/

t_bool	ant_can_move(t_room *room)
{
	if ((room->ants == 0 && room->type == standard) || (room->type == end))
		return (true);
	return (false);
}
