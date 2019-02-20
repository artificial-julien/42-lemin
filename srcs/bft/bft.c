/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:05:48 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/20 13:09:46 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Breadth-first traverse information functions.
*/

t_bft	*bft_new(int rooms_count)
{
	t_bft	*res;

	res = ft_memalloc(sizeof(t_bft));
	res->virtual_route = route_new();
	res->forbidden = bitmap_new(rooms_count);
	return (res);
}

void	bft_free(void *content, size_t size)
{
	t_bft	*bft;

	(void)size;
	bft = (t_bft*)content;
	bitmap_free(bft->forbidden);
	route_free(bft->virtual_route, sizeof(t_route));
	free(bft);
}

void	bft_add_node(t_bft *bft, t_room *room)
{
	route_add_node(bft->virtual_route, room);
}

t_bft	*bft_copy(t_bft *bft)
{
	t_bft	*res;

	res = ft_memalloc(sizeof(t_bft));
	res->augment_count = bft->augment_count;
	res->virtual_route = route_copy(bft->virtual_route);
	res->forbidden = bitmap_copy(bft->forbidden);
	return (res);
}

/*
**	After reaching an existing route, for flow augmentation,
**	extends the virtual route to the start by following the existing route.
*/

void	bft_run_to_start(t_bft *bft)
{
	t_room	*curr;

	curr = bft->virtual_route->rooms->room->prev;
	while (curr != NULL)
	{
		bft_add_node(bft, curr);
		curr = curr->prev;
	}
}
