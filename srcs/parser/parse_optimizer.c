/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optimizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/27 19:10:56 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Remove a room dead_end from all the list links of all the room of lem.
**	Removes a room with a dead end and the whole way.
*/

void	delete_dead_end(t_lem_in *lem_in, t_room *dead_end)
{
	t_room	*next;
	t_room	*curr;

	(void)lem_in;
	curr = dead_end;
	while (curr->type == standard && curr->links_count <= 1)
	{
		next = curr->links->room;
		room_remove_link(next, curr);
		lem_in_remove_room(lem_in, curr);
		curr = next;
	}
}

/*
**	Clean rooms with dead ends.
*/

void	parse_optimizer(t_lem_in *lem_in)
{
	t_glist		*curr;
	t_room		*room;
	int			cpt;

	cpt = 0;
	if (lem_in->opt.print_room == true || lem_in->opt.debug == true)
		lem_in_print_all_rooms(lem_in);
	room = NULL;
	curr = lem_in->rooms;
	while (curr)
	{
		room = curr->room;
		if (room->links_count <= 1 && room->type == standard)
		{
			delete_dead_end(lem_in, room);
			curr = lem_in->rooms;
			cpt++;
		}
		else
			curr = curr->next;
	}
	if (cpt != 0
		&& (lem_in->opt.print_room == true || lem_in->opt.debug == true))
		lem_in_print_all_rooms(lem_in);
}
