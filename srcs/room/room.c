/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:16:36 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/19 15:09:41 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Creates a new room.
*/

t_room	*room_new(char *name, t_roomtype type, int x, int y)
{
	t_room		*res;
	static int	id;

	res = ft_memalloc(sizeof(t_room));
	res->id = id;
	res->name = ft_strdup(name);
	res->type = type;
	res->pos.x = x;
	res->pos.y = y;
	id++;
	return (res);
}

/*
**	Returns the room with the specified name.
*/

t_room	*room_find_by_name(t_lem_in *lem_in, char *name)
{
	t_glist	*curr;

	curr = lem_in->rooms;
	while (curr != NULL)
	{
		if (ft_strequ(((t_room*)curr->content)->name, name))
			return ((t_room*)curr->content);
		curr = curr->next;
	}
	lem_in_die();
	return (NULL);
}

/*
**	Adds a room connection to another room using room names.
*/

void	room_add_link(t_lem_in *lem_in, char *origin, char *target)
{
	t_room	*origin_room;
	t_room	*target_room;
	t_glist	*new;

	origin_room = room_find_by_name(lem_in, origin);
	target_room = room_find_by_name(lem_in, target);
	new = ft_glstnew(target_room, sizeof(t_room));
	ft_glstadd(&origin_room->links, new);
	origin_room->links_count++;
	target_room->links_count++;
}

/*
**	Sets the number of ants.
*/

void	room_set_ants(t_room *room, int ants)
{
	room->ants = ants;
}

/*
**	Removes the specified link from the room.
*/

void	room_remove_link(t_room *room, t_room *link)
{
	t_glist	**curr;

	curr = &room->links;
	while (*curr != NULL)
	{
		if ((*curr)->room == link)
		{
			ft_glstdelone(curr, NULL);
			return ;
		}
		curr = &(*curr)->next;
	}
#if DEBUG

	ft_putendl_fd("Link not found", 2);
	lem_in_die();
#endif

}

/*
**	Free the specified room object and its elements.
**	Use with ft_glistdel()
*/

void	room_free(void *content, size_t size)
{
	t_room *room;

	(void)size;
	room = (t_room*)content;
	free(room->name);
	ft_glstdel(&room->links, NULL);
}
