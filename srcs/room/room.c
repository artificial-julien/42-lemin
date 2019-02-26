/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:16:36 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/26 19:21:22 by agoulas          ###   ########.fr       */
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
** return if a name is has a duplicat in a sorted list.
*/

t_bool	room_find_duplicate_name(t_lem_in *lem_in)
{
	int		pos;
	char	*curr;
	char	*curr_next;

	pos = 0;
	while (lem_in
		&& (pos + 1) < lem_in->room_count
		&& lem_in->array_room)
	{
		curr = lem_in->array_room[pos]->name;
		curr_next = lem_in->array_room[pos + 1]->name;
		if (ft_strcmp(curr, curr_next) == 0)
			return (true);
		pos++;
	}
	return (false);
}

/*
**	Returns the room with the specified name.
*/

t_room	*room_find_by_name(t_lem_in *lem_in, char *name)
{
	int		pos;
	int		size;
	int		cmp;
	t_room	*room;

	pos = lem_in->room_count / 2;
	size = lem_in->room_count;
	while (pos >= 0 && pos < size)
	{
		room = lem_in->array_room[pos];
		if ((cmp = ft_strcmp(name, room->name)) == 0)
			return ((t_room*)lem_in->array_room[pos]);
		else
		{
			if (cmp < 0)
				pos = pos / 2;
			else
				pos++;
		}
	}
	lem_in_die();
	return (NULL);
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

/*
**	Sort by lexical order the two room.
*/

int		room_cmp(void *a, void *b)
{
	t_room	*room_a;
	t_room	*room_b;

	room_a = (t_room*)a;
	room_b = (t_room*)b;
	return (ft_strcmp(room_a->name, room_b->name));
}
