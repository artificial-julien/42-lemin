/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:05:48 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/18 19:49:03 by juazouz          ###   ########.fr       */
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
	res->forbidden = bitmap_new(rooms_count);
	return (res);
}

void	bft_free(t_bft *bft)
{
	bitmap_free(bft->forbidden);
	free(bft);
}

void	bft_forbid(t_bft *bft, int room_id)
{
	bitmap_set(bft->forbidden, room_id);
}

void	bft_add_node(t_bft *bft, t_room *room)
{
	route_add_node(bft->route, room);
}

t_bft	*bft_copy(t_bft *bft)
{
	t_bft	*res;

	res = ft_memalloc(sizeof(t_bft));
	ft_memcpy(res, bft, sizeof(t_bft));
	res->forbidden = bitmap_copy(bft->forbidden);
	return (res);
}
