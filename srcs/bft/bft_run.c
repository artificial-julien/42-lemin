/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/20 17:21:40 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define NONE 0
#define STANDARD 1
#define RUN_TO_START 2
#define FINAL 3

/*
**	============= breadth-first traversal execution =============
*/

/*
**	Returns the traverse possibility for the specified node.
*/

static int		can_traverse_node(t_bft *bft, t_room *src, t_room *dst)
{
	if (src->next != NULL && src->next == dst)
	{
		return (NONE);
	}
	if (bitmap_get(bft->forbidden, dst->id))
	{
		return (NONE);
	}
	if (dst->type == end)
	{
		return (FINAL);
	}
	if (dst->prev != NULL && dst->prev != src)
	{
		return (RUN_TO_START);
	}
	if (dst->prev != NULL && dst->prev == src)
	{
		return (NONE);
	}
	return (STANDARD);
}

/*
**	Returns true if the bft reached a successful end.
**	Stores the new bft information.
*/

static int		try_traverse_node(t_bft *bft, t_room *src, t_room *dst, t_bft **new_bft)
{
	int		traverse_mode;

	traverse_mode = can_traverse_node(bft, src, dst);
	if (traverse_mode == NONE)
	{
		return (NONE);
	}
	*new_bft = bft_copy(bft);
	bft_add_node(*new_bft, dst);
	if (src->next == NULL && dst->prev != NULL)
	{
		bft_add_node(*new_bft, dst->prev);
	}

	return (traverse_mode);
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
	int		traverse_res;

	last_room = bft->virtual_route->rooms->room;
	bitmap_set(bft->forbidden, last_room->id);
	curr = last_room->links;
// #ifdef DEBUG

// 	ft_fprintf(2, "\nExtending from:\t");
// 	route_print(bft->virtual_route);
// #endif

	while (curr != NULL)
	{
		traverse_res = try_traverse_node(bft, last_room, curr->room, &new_bft);
		if (traverse_res == FINAL)
		{
// #ifdef DEBUG

// 			ft_fprintf(2, "Found:\t\t");
// 			route_print((new_bft)->virtual_route);
// #endif

			return (new_bft);
		}
		else if (traverse_res != NONE)
		{
// #ifdef DEBUG

// 			ft_fprintf(2, "Extending to:\t");
// 			route_print((new_bft)->virtual_route);
// #endif

			new_node = ft_glstnew(new_bft, sizeof(t_bft));
			ft_glstadd(next_nodes, new_node);
		}
		curr = curr->next;
	}
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

t_bft			*bft_run(t_bft *initial)
{
	t_bft	*initial_cpy;
	t_glist	*nodes;
	t_glist	*next_nodes;
	t_bft	*res;

	nodes = NULL;
	initial_cpy = bft_copy(initial);
	ft_glstadd(&nodes, ft_glstnew(initial_cpy, sizeof(t_bft)));
	next_nodes = NULL;
	while (1)
	{
		res = extend_nodes_list(nodes, &next_nodes);
		if (res != NULL)
			res = bft_copy(res);
		else if (next_nodes == NULL)
			return (NULL);
		// ft_glstdel(&nodes, bft_free);
		if (res != NULL)
		{
			// ft_glstdel(&next_nodes, bft_free);
			return (res);
		}
		nodes = next_nodes;
		next_nodes = NULL;
	}
}
