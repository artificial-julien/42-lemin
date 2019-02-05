/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:40:34 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/05 14:17:01 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Function to find if a route is in the list of routes
*/

t_bool	routes_routechr(t_glist *routes, t_route *route)
{
	t_route *route_b;

	while (routes)
	{
		route_b = routes->content;
		if (route_equals(route, route_b) == 1)
			return (true);
		routes = routes->next;
	}
	return (false);
}

/*
** Function to compare if the route of the two list are the same.
*/

int		routes_equals(t_glist *routes_a, t_glist *routes_b)
{
	int			compteur;
	t_route		*route;

	compteur = 0;
	while (routes_a)
	{
		route = routes_a->route;
		if (routes_routechr(routes_b, route) == 1)
			compteur++;
		routes_a = routes_a->next;
	}
	return (compteur);
}
