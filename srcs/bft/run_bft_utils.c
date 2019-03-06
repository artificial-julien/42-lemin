/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bft_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:56:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 19:27:37 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns the actual traverse destination for the specified node.
**	Returns NULL when the destination is not possible.
*/

t_bool		can_traverse(t_route_tree *tree, t_room *dst)
{
	if (dst->visited)
		return (false);
	if (tree->room->prev != NULL && tree->room->prev == dst)
		return (false);
	if (tree->intersection == dst)
		return (false);
	if (tree->intersection != NULL
		&& tree->room == tree->intersection
		&& dst != tree->room->next)
	{
		return (false);
	}
	if (tree->room->type == start && dst->prev == tree->room)
		return (false);
	if (dst->type == start)
		return (false);
	return (true);
}

/*
**	Returns true if going from src to dst means stepping IN an existant route.
*/

t_bool		in_intersection(t_room *src, t_room *dst)
{
	if (src->next != NULL && src->next == dst)
		return (false);
	if (dst->prev == NULL)
		return (false);
	if (dst->prev == src)
		return (false);
	return (true);
}

/*
**	Returns true if going from src to dst means stepping OUT of an existant
**	route.
*/

static t_bool		out_intersection(t_room *src, t_room *dst)
{
	return (src->next != NULL && src->next != dst);
}

/*
**	Continues the traverse from the first node of the existant route we are on.
**	Returns null if the last intersection is the first node of the route.
*/

static t_route_tree	*go_to_start(t_lem_in *lem_in, t_route_tree *tree)
{
	t_room			*room;
	t_route_tree	*res;

	room = tree->parent->room;
	while (room->prev->type != start)
	{
		room = room->prev;
	}
	if (tree->intersection == room)
	{
		return (NULL);
	}
	res = route_tree_create_child(lem_in, tree, lem_in->start);
	res = route_tree_create_child(lem_in, res, room);
	res->augmentation++;
	return (res);
}
