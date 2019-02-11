/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/05 13:22:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

/*
** Move the ants forn a room to another and print the move.
*/

void move_ants(t_room **src, t_room **dest, t_solution *solution)
{
	if ((*src)->ants > 0 && (ants_can_move((*dest)) == 1))
	{
		(*src)->ants--;
		(*dest)->ants++;
		ft_printf("L%s%%s ",(*src)->name,solution->rounds,(*dest)->name);
	}
}


/*
**	Function testing the links for if the next room is empty
*/

t_bool	ants_can_move(t_room *room)
{
	if ((room->ants == 0 && room->type == standard) || (room->type == end))
		return (1);
	return (0);
}
