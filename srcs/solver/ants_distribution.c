/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:38:13 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 15:49:00 by juazouz          ###   ########.fr       */
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
	t_glist	*curr;

	i = 0;
	p = 0;
	curr = group->routes;
	while (curr != NULL)
	{
		i++;
		p += curr->route->len;
		if (p >= total_ants)
			return (i);
		curr = curr->next;
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
	t_glist	*curr;
	int		i;

	res = total_ants;
	curr = group->routes;
	i = 0;
	while (i < routes_count)
	{
		if (curr == NULL)
			lem_in_die();
		res += curr->route->len;
		curr = curr->next;
		i++;
	}
	return (res);
}

/*
**	Distributes the ants.
*/

static void	distribute(t_group *group, int grand_total, int *array, int size)
{
	int		i;
	int		average;
	int		remainder;
	t_glist	*curr;

	remainder = grand_total % size;
	average = grand_total / size;
	curr = group->routes;
	i = 0;
	while (i < size)
	{
		array[i] = average - curr->route->len;
		i++;
		curr = curr->next;
	}
	i = 0;
	while (i < remainder)
	{
		array[i]++;
		i++;
	}
}

/*
**	Stores and array of ants to move in to routes.
**	Returns the array size.
*/

int			ants_distribution(t_group *group, int total_ants, int **res)
{
	int		routes_count;
	int		grand_total;

	routes_count = routes_use_count(group, total_ants);
	grand_total = get_grand_total(group, total_ants, routes_count);
	*res = ft_memalloc(sizeof(int) * routes_count);
	distribute(group, grand_total, *res, routes_count);
	return (routes_count);
}
