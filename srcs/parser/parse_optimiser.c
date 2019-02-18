/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_optimiser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/08 17:32:12 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	delete_link_room(t_room *room, char *dead_end)
{
	t_glist *links;
	t_glist *curr;

	links = room->links;
	if (ft_strequ(links->room->name, dead_end) == true)
	{

		room->links = room->links->next;
		links->next = NULL;
		ft_glstdelone(&links, room_free);
	}
	while (links->next != NULL)
	{
		if (ft_strequ(links->next->room->name, dead_end) == true)
		{
			curr = links->next;
			links = links->next->next;
			ft_glstdelone(&curr, room_free);
		}
		links = links->next;
	}
}

void	delete_dead_end(t_lem_in *lem_in, char *dead_end)
{
	t_glist	*rooms;
	t_room	*curr;

	rooms = lem_in->rooms;
	while(rooms->room != NULL)
	{
		curr = rooms->room;
		delete_link_room(curr, dead_end);
		rooms = rooms->next;
	}
	rooms = lem_in->rooms;
	while(rooms->room != NULL)
	{
		curr = rooms->room;
		if ()
		rooms = rooms->next;
	}

}


void parse_optimiser(t_lem_in *lem_in)
{
	t_glist		*rooms;
	t_room		*room;

	rooms = lem_in->rooms;
	while(rooms->room != NULL)
	{
		room = rooms->room;
		if ((room->links_count) <= 1)
		{
			delete_dead_end(lem_in, room->name);
		}
		rooms = rooms->next;
	}
}
