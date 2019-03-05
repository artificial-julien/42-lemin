/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:19:01 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/05 11:34:37 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	min(int a, int b)
{
	return (a > b ? b : a);
}

/*
**	Returns the number of max possible routes.
**	Matches the minimum among of outgoing routes from the start and end nodes
**	and the number of ants.
*/

int			max_routes(t_lem_in *lem_in)
{
	int	res;
	int	start;
	int	end;

	start = lem_in->start->links_count;
	end = lem_in->end->links_count;
	res = min(start, end);
	res = min(res, lem_in->total_ants);
	return (res);
}
