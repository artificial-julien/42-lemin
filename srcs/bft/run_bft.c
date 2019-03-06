/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 18:52:15 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	============= breadth-first traversal execution =============
*/

/*
**	Returns the actual traverse destination for the specified node.
**	Returns NULL when the destination is not possible.
*/

static t_bool		can_traverse(t_route_tree *tree, t_room *dst)
{
	if (dst->visited)
	{
		return (false);
	}
	if (tree->room->prev != NULL && tree->room->prev == dst)
	{
		return (false);
	}
	if (tree->intersection == dst)
	{
		return (false);
	}
	if (tree->intersection != NULL
		&& tree->room == tree->intersection
		&& dst != tree->room->next)
	{
		return (false);
	}
	if (tree->room->type == start && dst->prev == tree->room)
	{
		return (false);
	}
	if (dst->type == start)
	{
		return (false);
	}
	return (true);
}

/*
**	Returns true if going from src to dst means stepping IN an existant route.
*/

static t_bool		in_intersection(t_room *src, t_room *dst)
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
**	Returns true if going from src to dst means stepping OUT of an existant route.
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

static t_route_tree	*traverse(t_lem_in *lem_in, t_route_tree *node, t_room *dst)
{
	t_route_tree	*res;
	int				augmentation;
	t_room			*intersection;

	if (!can_traverse(node, dst))
		return (NULL);
	augmentation = node->augmentation;
	if (in_intersection(node->room, dst))
	{
		augmentation--;
		if (augmentation < 0)
			return (NULL);
		intersection = dst;
	}
	else if (out_intersection(node->room, dst))
		intersection = NULL;
	else
		intersection = node->intersection;
	res = route_tree_create_child(lem_in, node, dst);
	res->augmentation = augmentation;
	res->intersection = intersection;
	if (lem_in->opt.debug)
	{
		ft_fprintf(2, "Extending to:\t");
		route_tree_print(res);
	}
	return (res);
}

static t_route_tree	*traverse_end(t_lem_in *lem_in, t_route_tree *node)
{
	t_route_tree	*res;

	if (node->parent->room->next != NULL)
	{
		res = go_to_start(lem_in, node);
		if (lem_in->opt.debug)
		{
			ft_fprintf(2, "Extending to (from start):\t");
			route_tree_print(res);
		}
		return (res);
	}
	return (NULL);
}

static t_route	*try_finalize_traverse(t_lem_in *lem_in, t_route_tree *node)
{
	if (node->augmentation > 0)
	{
		if (lem_in->opt.debug)
		{
			ft_fprintf(2, "Found:\t\t");
			route_tree_print(node);
		}
		return (route_tree_to_route(node));
	}
	return (NULL);
}

/*
**	Iterates over current level node connections.
**	Stores the new list of node's connections.
**	Returns the found path if any.
*/

static t_route		*extend_node(t_lem_in *lem_in, t_route_tree *node, t_glist **next_nodes)
{
	t_glist			*curr;
	t_route_tree	*new_node;
	static int		debug_pass;
	t_route			*res;

	debug_pass++;
	new_node = NULL;
	if (lem_in->opt.debug)
	{
		ft_fprintf(2, "\nPass #%d\n", debug_pass);
		ft_fprintf(2, "Extending from (augmentations=%d, intersection=%s):\t", node->augmentation, node->intersection != NULL ? node->intersection->name : NULL);
		route_tree_print(node);
	}
	if (node->room->type == standard && node->room->next == NULL)
		node->room->visited = true;
	if (node && node->room->type == end)
	{
		if ((res = try_finalize_traverse(lem_in, node)) != NULL)
			return (res);
		new_node = traverse_end(lem_in, node);
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
	}
	else
	{
		curr = node->room->links;
		while (curr != NULL)
		{
			new_node = traverse(lem_in, node, curr->room);
			if (new_node != NULL)
				ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
			curr = curr->next;
		}
	}
	return (NULL);
}

/*
**	Iterates over current level nodes.
**	Stores a list of the next level nodes.
**	Returns the tree leaf of the first found path if any.
*/

static t_route		*extend_nodes_list(t_lem_in *lem_in, t_glist *nodes, t_glist **next_nodes)
{
	t_glist		*curr;
	t_route		*res;

	curr = nodes;
	while (curr != NULL)
	{
		if ((res = extend_node(lem_in, curr->tree, next_nodes)))
			return (res);
		curr = curr->next;
	}
	return (NULL);
}

/*
**	Runs breadth-first traverse through the graph and builds routes.
**	Returns a virtual route.
**	Returns null if no relevant traverse path are found.
*/

t_route				*run_bft(t_lem_in *lem_in)
{
	t_glist			*nodes;
	t_glist			*next_nodes;
	t_route			*res;
	t_route_tree	*tree;

	nodes = NULL;
	tree = route_tree_new(lem_in);
	tree->room = lem_in->start;
	tree->augmentation = 1;
	ft_glstadd(&nodes, ft_glstnew(tree, sizeof(t_route_tree)));
	next_nodes = NULL;
	while (1)
	{
		res = extend_nodes_list(lem_in, nodes, &next_nodes);
		route_tree_del_list(lem_in, &nodes);
		if (res != NULL)
		{
			route_tree_del_list(lem_in, &next_nodes);
			return (res);
		}
		if (next_nodes == NULL)
			return (NULL);
		nodes = next_nodes;
		next_nodes = NULL;
	}
}
