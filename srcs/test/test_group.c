/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/06 17:28:18 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lem_in_tests.h"

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

/*
** group
*/
	t_group *g1;
	t_group *g2;
	t_group *g3;

	g1 = group_new();
	g2 = group_new();
	g3 = group_new();


	group_add_route(g1, route1);
	group_add_route(g1, route2);
	group_add_route(g1, route3);

	group_add_route(g2, route2);
	group_add_route(g2, route1);
	group_add_route(g2, route3);

	group_add_route(g3, route3);
	group_add_route(g3, route1);
	group_add_route(g3, route1);

	if (group_equals(g1, g2) == 1)
		ft_printf("gr 1 et 2 sont equals\n");
	else
		ft_printf("gr 1 et 2 error\n");
	if (group_equals(g1, g3) == 1)
		ft_printf("gr 1 et 3 sont equals\n");
	else
		ft_printf("gr 1 et 3 error\n");
	if (group_equals(g2, g3) == 1)
		ft_printf("gr  2 et 3 sont equals\n");
	else
		ft_printf("gr 2 et 3 error\n");
	(void)lem_in;
}

int main(void)
{
	t_lem_in	lem_in;
	t_solution	solution;
	t_glist		*routes;
	t_glist		*groups;

	routes = NULL;
	groups = NULL;
	lem_in_init(&lem_in);
	dummy_map_01(&lem_in);
	routes = create_routes(&lem_in);
	create_groups(&groups, routes);
	solution.rounds = NULL;
	dummy_solution(&lem_in);
	return (1);
}
