/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:13:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 20:39:48 by juazouz          ###   ########.fr       */
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

static t_room	*route_start(t_room *room)
{
	t_room	*res;

	res = room;
	while (res->prev->type != start)
	{
		res = res->prev;
	}
	return (res);
}

/*
**	Breaks an encountered existant route.
*/

static void		break_route(t_room *room)
{
	t_room	*curr;
	t_room	*next;

	curr = route_start(room);
	ft_fprintf(2, "Breaking route starting at %s (encountered at %s)\n", curr->name, room->name);
	while (curr->type == standard)
	{
		next = curr->next;
		curr->prev = NULL;
		curr->next = NULL;
		curr = next;
	}
}

/*
**	Updates the nodes connections (prev, next) representing the routes on
**	the map using the virtual route created by the Edmonds-Karp traverse.
*/

void			rebuild_routes(t_lem_in *lem_in, t_route *route)
{
	t_glist	*curr;
	t_room	*prev;

	(void)lem_in;
	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		if (has_route(curr->room))
		{
			break_route(curr->room);
		}
		prev = curr->room;
		curr = curr->next;
	}
	curr = route->rooms;
	prev = NULL;
	while (curr != NULL)
	{
		connect(prev, curr->room);
		prev = curr->room;
		curr = curr->next;
	}
}
