/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optimizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/21 15:14:57 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Remove a room dead_end from all the list links of all the room of lem.
*/

void	delete_dead_end(t_lem_in *lem_in, t_room *dead_end)
{
	t_glist	*rooms;
	t_room	*curr;

	rooms = lem_in->rooms;
	while (rooms != NULL && dead_end)
	{
		curr = rooms->room;
		room_remove_link(curr, dead_end);
		rooms = rooms->next;
	}
}

/*
**	Remove all room of type dead_end : with no links to advance.
*/

void	parse_optimizer(t_lem_in *lem_in)
{
	t_glist		*curr;
	t_room		*room;

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
			lem_in_remove_room(lem_in, room);
			curr = lem_in->rooms;
		}
		else
			curr = curr->next;
	}
	if (lem_in->opt.print_room == true || lem_in->opt.debug == true)
		lem_in_print_all_rooms(lem_in);
}
