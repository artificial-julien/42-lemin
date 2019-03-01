/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebuild_routes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 16:13:44 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 16:29:59 by juazouz          ###   ########.fr       */
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
		connect(prev, curr->room);
		prev = curr->room;
		curr = curr->next;
	}
}
