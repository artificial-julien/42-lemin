/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_routes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/04 16:25:47 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define ROOMS_COUNT 3
#define ROUTES_COUNT 3

void dummy_solution(t_lem_in *lem_in)
{

	t_room *rooms[ROOMS_COUNT];
	t_route *route1;
	t_route *route2;
	t_route *route3;

	route1 = NULL;
	route2 = NULL;
	route3 = NULL;
	rooms[0] = room_new("0", start, 0, 0);
	rooms[1] = room_new("1", standard, 0, 0);
	rooms[2] = room_new("2", end, 0, 0);
	route1 = malloc(sizeof(t_route));
	route2 = malloc(sizeof(t_route));
	route3 = malloc(sizeof(t_route));
	route3->id_route = 3;
	route2->id_route = 3;
	route1->id_route = 3;
	route1->len = 3;
	route2->len = 3;
	route3->len = 3;
	ft_glstadd(&(route1)->rooms, ft_glstnew(rooms[0], 1));
	ft_glstadd(&(route1)->rooms, ft_glstnew(rooms[1], 1));
	ft_glstadd(&(route1)->rooms, ft_glstnew(rooms[2], 1));

	ft_glstadd(&(route2)->rooms, ft_glstnew(rooms[0], 1));
	ft_glstadd(&(route2)->rooms, ft_glstnew(rooms[1], 1));
	ft_glstadd(&(route2)->rooms, ft_glstnew(rooms[2], 1));

	ft_glstadd(&(route3)->rooms, ft_glstnew(rooms[2], 1));
	ft_glstadd(&(route3)->rooms, ft_glstnew(rooms[0], 1));
	ft_glstadd(&(route3)->rooms, ft_glstnew(rooms[1], 1));

	int i;
	i = 0;
	while (i < ROOMS_COUNT)
	{
		lem_in_add_room(lem_in, rooms[i]);
		i++;
	}
	if (route_equals(route1, route2) == 1)
		ft_fprintf(2, " 1 et 2 sont equals\n");
	else
		ft_fprintf(2, "1 et 2 error\n");
	if (route_equals(route1, route3) == 1)
		ft_fprintf(2, " 1 et 3 sont equals\n");
	else
		ft_fprintf(2, "1 et 3 error\n");
	if (route_equals(route2, route3) == 1)
		ft_fprintf(2, " 2 et 3 sont equals\n");
	else
		ft_fprintf(2, "2 et 3 error\n");
}

int main(void)
{
	t_lem_in lem_in;
	t_solution solution;

	lem_in_init(&lem_in);
	solution.rounds = NULL;
	dummy_solution(&lem_in);
	return (1);
}
