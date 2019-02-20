/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:13:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/20 17:17:45 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Connects two node. Updates all relevant informations on all sides.
**	Disconnected newly unrelated nodes.
*/

static void		connect(t_room *prev, t_room *next)
{
	if (next->prev != prev && next->prev != NULL)
	{
		next->prev->next = NULL;
	}
	if (prev != NULL && prev->type == standard)
	{
		prev->next = next;
	}
	if (next->type == standard)
	{
		next->prev = prev;
	}
}

static void		disconnect(t_room *prev, t_room *next)
{
	prev->next = NULL;
	next->prev = NULL;
}

static t_bool	broken_connection(t_room *node)
{
	return (node->prev != NULL && node->next == NULL);
}

static t_bool	connected(t_room *prev, t_room *next)
{
	if (prev->next == NULL || next->prev == NULL)
		return (false);
	return (prev->next == next && next->prev == prev);
}

/*
**	Updates the nodes connections (prev, next) representing the routes on
**	the map using the virtual route created by the Edmonds-Karp traverse.
*/

void			rebuild_routes(t_route *route)
{
	t_glist	*curr;
	t_room	*prev;

	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		if (broken_connection(curr->room))
		{
			if (connected(curr->room, prev))
			{
				disconnect(curr->room, prev);
			}
		}
		else
		{
			connect(prev, curr->room);
		}
		prev = curr->room;
		curr = curr->next;
	}
}
