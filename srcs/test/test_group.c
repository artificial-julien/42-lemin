/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/06 18:25:12 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lem_in_tests.h"

#define ROOMS_COUNT 3
#define ROUTES_COUNT 3

static void	group_print(t_group *group)
{
	t_glist	*curr;

	ft_printf("Group:\n");
	curr = group->routes;
	while (curr != NULL)
	{
		route_print(curr->route);
		curr = curr->next;
	}
}

static void	print_groups(t_glist *groups)
{
	t_glist	*curr;

	curr = groups;
	while (curr != NULL)
	{
		group_print(curr->group);
		curr = curr->next;
	}
}

int			main(void)
{
	t_lem_in	lem_in;
	t_glist		*routes;
	t_glist		*groups;

	routes = NULL;
	groups = NULL;
	lem_in_init(&lem_in);
	dummy_map_01(&lem_in);
	routes = create_routes(&lem_in);
	create_groups(&groups, routes);
	print_groups(groups);
	return (1);
}
