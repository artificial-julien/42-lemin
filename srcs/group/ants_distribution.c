/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:38:13 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 15:22:07 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns the total number of routes needed.
*/

static int	routes_use_count(t_group *group, int total_ants)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (i < group->route_count)
	{
		p += group->routes[i]->len - 1;
		i++;
		if (p >= total_ants)
			return (i);
	}
	return (i);
}

/*
**	Returns the grand total (total ants + sum of the len of used routes).
**	Math used for ants distribution.
*/

static int	get_grand_total(t_group *group, int total_ants, int routes_count)
{
	int		res;
	int		i;

	res = total_ants;
	i = 0;
	while (i < routes_count)
	{
		res += group->routes[i]->len;
		i++;
	}
	return (res);
}

/*
**	Distributes the ants.
*/

static void	distribute(t_group *group, int grand_total, int *tab, int size)
{
	int		i;
	int		average;
	int		remainder;

	remainder = grand_total % size;
	average = grand_total / size;
	i = 0;
	while (i < size)
	{
		tab[i] = average - group->routes[i]->len;
		i++;
	}
	i = 0;
	while (i < remainder)
	{
		tab[i]++;
		i++;
	}
}

/*
**	Stores and array of the number of ants to move in to routes.
*/

void		distribute_ants(t_group *group, int total_ants, int *tab)
{
	int		routes_count;
	int		grand_total;

	routes_count = routes_use_count(group, total_ants);
	grand_total = get_grand_total(group, total_ants, routes_count);
	distribute(group, grand_total, tab, routes_count);
}
