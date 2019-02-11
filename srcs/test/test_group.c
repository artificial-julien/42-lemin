/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:51:25 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/11 16:10:58 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "lem_in_tests.h"

#define ROOMS_COUNT 3
#define ROUTES_COUNT 3

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
	parse(&lem_in);
	routes = create_routes(&lem_in);
	create_groups(&groups, routes);
	print_groups(groups);
	return (1);
}
