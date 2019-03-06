/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_create_links.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/06 19:31:59 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** FInd if a room is already in the list links.
*/

static t_bool	room_find_duplicate_link(t_room *room, char *name)
{
	t_glist	*curr;

	if (room->links == NULL && room->links_count == 0)
		return (false);
	curr = room->links;
	while (curr)
	{
		if (ft_strequ(curr->gen.room->name, name))
			return (true);
		curr = curr->next;
	}
	return (false);
}

/*
**	Adds a room connection to another room using room names.
*/

void			room_add_link(t_lem_in *lem_in, char *origin, char *target)
{
	t_room	*origin_room;
	t_room	*target_room;
	t_glist	*new_o;
	t_glist	*new_t;

	origin_room = room_find_by_name(lem_in, origin);
	target_room = room_find_by_name(lem_in, target);
	if (room_find_duplicate_link(origin_room, target) == false)
	{
		new_t = ft_glstnew(target_room, sizeof(t_room));
		ft_glstadd(&origin_room->links, new_t);
		origin_room->links_count++;
		new_o = ft_glstnew(origin_room, sizeof(t_room));
		ft_glstadd(&target_room->links, new_o);
		target_room->links_count++;
	}
}

/*
**	Removes the specified link from the room.
*/

void			room_remove_link(t_room *room, t_room *link)
{
	t_glist	**curr;

	curr = &room->links;
	while (*curr != NULL)
	{
		if ((*curr)->gen.room == link)
		{
			ft_glstdelone(curr, NULL);
			room->links_count--;
			return ;
		}
		curr = &(*curr)->next;
	}
}
