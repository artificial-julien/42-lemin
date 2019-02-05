/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dummy_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:14:22 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 16:24:47 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Set of functions loading dummy maps into the lem_in core structure.
*/

static void	add_rooms(t_lem_in *lem_in, t_room **rooms, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		lem_in_add_room(lem_in, rooms[i]);
		i++;
	}
}

#define ROOMS_COUNT 8

void	dummy_map_01(t_lem_in *lem_in)
{
	t_room	*rooms[ROOMS_COUNT];

	rooms[0] = room_new("S", start, 0, 0);
	rooms[1] = room_new("1", standard, 0, 0);
	rooms[2] = room_new("2", standard, 0, 0);
	rooms[3] = room_new("3", standard, 0, 0);
	rooms[4] = room_new("4", standard, 0, 0);
	rooms[5] = room_new("5", standard, 0, 0);
	rooms[6] = room_new("6", standard, 0, 0);
	rooms[7] = room_new("E", end, 0, 0);
	add_rooms(lem_in, rooms, ROOMS_COUNT);
	lem_in->start = rooms[0];
	lem_in->end = rooms[7];
	room_add_link(lem_in, rooms[0]->name, rooms[1]->name);
	room_add_link(lem_in, rooms[1]->name, rooms[2]->name);
	room_add_link(lem_in, rooms[2]->name, rooms[3]->name);
	room_add_link(lem_in, rooms[3]->name, rooms[7]->name);
	room_add_link(lem_in, rooms[0]->name, rooms[4]->name);
	room_add_link(lem_in, rooms[4]->name, rooms[5]->name);
	room_add_link(lem_in, rooms[5]->name, rooms[6]->name);
	room_add_link(lem_in, rooms[6]->name, rooms[7]->name);
	room_add_link(lem_in, rooms[1]->name, rooms[6]->name);
}
