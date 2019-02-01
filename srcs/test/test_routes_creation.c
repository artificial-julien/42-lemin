/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_routes_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:48:14 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 19:06:07 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ROOMS_COUNT 8

void	dummy_map(t_lem_in *lem_in)
{
	t_room	*rooms[ROOMS_COUNT];
	int	i;

	rooms[0] = room_new("S", start, 0, 0);
	rooms[1] = room_new("1", standard, 0, 0);
	rooms[2] = room_new("2", standard, 0, 0);
	rooms[3] = room_new("3", standard, 0, 0);
	rooms[4] = room_new("4", standard, 0, 0);
	rooms[5] = room_new("5", standard, 0, 0);
	rooms[6] = room_new("6", standard, 0, 0);
	rooms[7] = room_new("E", end, 0, 0);

	lem_in->start = rooms[0];
	lem_in->end = rooms[7];

	i = 0;
	while (i < ROOMS_COUNT)
	{
		lem_in_add_room(lem_in, rooms[i]);
		i++;
	}
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

int			main(void)
{
	t_lem_in	lem_in;

	lem_in_init(&lem_in);
	dummy_map(&lem_in);
	create_nodes_weights(&lem_in);
	lem_in_free(&lem_in);
	return (0);
}
