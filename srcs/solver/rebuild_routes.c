/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:13:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 16:49:53 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Connects two node. Do not affects the start or end rooms.
*/

static void		connect(t_room *prev, t_room *next)
{
	if (prev != NULL && prev->type != standard && next->type != standard)
	{
		return ;
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

static t_bool	has_route(t_room *room)
{
	return (room->next != NULL && room->prev != NULL);
}

/*
**	Breaks an encountered existant route.
*/

static void		break_route(t_room *room)
{
	t_room	*curr;
	t_room	*next;

	curr = room->next;
	while (curr->type != standard)
	{
		next = curr->next;
		curr->prev = NULL;
		curr->next = NULL;
		curr = next;
	}
	curr = room->prev;
	while (curr->type != standard)
	{
		next = curr->prev;
		curr->prev = NULL;
		curr->next = NULL;
		curr = next;
	}
	room->prev = NULL;
	room->next = NULL;
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
		if (has_route(curr->room))
		{
			break_route(curr->room);
		}
		connect(prev, curr->room);
		prev = curr->room;
		curr = curr->next;
	}
}
