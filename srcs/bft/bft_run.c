/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/19 18:08:16 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	============= breadth-first traversal execution =============
*/

static t_bool	can_traverse_node(t_bft *bft, t_room *src, t_room *dst)
{
	(void)src;
	if (bitmap_get(bft->forbidden, dst->id))
		return (false);
	if (dst->prev != NULL && dst->prev == src)
		return (false);
	// if (dst->type == start && src->prev != dst)
	// 	return (false);
	// if (src->prev != NULL && src->prev != dst)
	// 	return (false);
	return (true);
}

/*
**	Returns true if the bft reached a successful end.
**	Stores the new bft information.
*/

static t_bool	traverse_node(t_bft *bft, t_room *dst, t_bft **new_bft)
{
#ifdef DEBUG

	ft_printf("Virtual route (before):\n");
	route_print(bft->virtual_route);
#endif

	*new_bft = bft_copy(bft);
	bft_add_node(*new_bft, dst);
	if (dst->type == end)
	{
		return (true);
	}
	// if (dst->type == start)
	// 	(*new_bft)->augment_count++;
	// if (dst->prev == NULL)
	{
	}
	if (dst->prev != NULL)
	{
		bft_run_to_start(*new_bft);
	}
#ifdef DEBUG

	ft_printf("Virtual route (after):\n");
	route_print((*new_bft)->virtual_route);
	ft_putendl("");
#endif

	return (false);
}

/*
**	Iterates over current level node connections.
**	Stores the new list of node's connections.
**	Returns the bft information of the found path.
*/

static t_bft	*extend_node(t_bft *bft, t_glist **next_nodes)
{
	t_glist	*curr;
	t_glist	*new_node;
	t_bft	*new_bft;
	t_room	*last_room;

	last_room = bft->virtual_route->rooms->room;
	bitmap_set(bft->forbidden, last_room->id);
	curr = last_room->links;
	while (curr != NULL)
	{
		if (can_traverse_node(bft, last_room, curr->room))
		{
			if (traverse_node(bft, curr->room, &new_bft))
			{
				bft_free(bft);
				return (new_bft);
			}
			new_node = ft_glstnew(new_bft, sizeof(t_bft));
			ft_glstadd(next_nodes, new_node);
		}
		curr = curr->next;
	}
	bft_free(bft);
	return (NULL);
}

/*
**	Iterates over current level nodes.
**	Stores a list of the next level nodes.
**	Returns the bft information of the found path.
*/

static t_bft	*extend_nodes_list(t_glist *nodes, t_glist **next_nodes)
{
	t_glist	*curr;
	t_bft	*res;

	curr = nodes;
	while (curr != NULL)
	{
		if ((res = extend_node(curr->bft, next_nodes)))
			return (res);
		curr = curr->next;
	}
	return (NULL);
}

/*
**	Runs breadth-first traverse through the graph and builds routes.
**	Returns the relevant breadth-first traverse information.
**	Returns null if no relevant traverse path are found.
*/

t_bft			*bft_run(t_room *start, int rooms_count)
{
	t_glist	*nodes;
	t_glist	*next_nodes;
	t_bft	*res;
	t_bft	*initial;

	initial = bft_new(rooms_count);
	bft_add_node(initial, start);
	nodes = NULL;
	ft_glstadd(&nodes, ft_glstnew(initial, sizeof(t_bft)));
	next_nodes = NULL;
	while ((res = extend_nodes_list(nodes, &next_nodes)) == NULL)
	{
		ft_glstdel(&nodes, NULL);
		if (next_nodes == NULL)
			lem_in_die();
		nodes = next_nodes;
		next_nodes = NULL;
	}
	return (res);
}
