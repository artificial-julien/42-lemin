/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_routes_creation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:48:14 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 14:27:24 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_routes(t_glist *routes)
{
	t_glist	*curr;

	curr = routes;
	while (curr != NULL)
	{
		route_print(curr->route);
		curr = curr->next;
	}
}

int			main(void)
{
	t_lem_in	lem_in;
	t_glist		*routes;

	lem_in_init(&lem_in);
	parse(&lem_in);
	routes = create_routes(&lem_in);
	print_routes(routes);
	lem_in_free(&lem_in);
	return (0);
}
