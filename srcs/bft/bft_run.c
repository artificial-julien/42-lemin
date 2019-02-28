/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/28 19:25:25 by juazouz          ###   ########.fr       */
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
**	Returns the actual traverse destination for the specified node.
**	Returns NULL when the destination is not possible.
*/

static t_bool		can_go_to(t_route_tree *tree, t_room *dst)
{
	// If going from start into an existing route.
	if (tree->room->type == start && dst->prev == tree->room)
	{
		return (false);
	}
	return (!dst->visited
		&& tree->intersection != dst);
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
	return (src->next != NULL && dst->prev != src);
}

/*
**	Extends the specified tree following the existant route to the first node
**	before start.
*/

static t_route_tree	*go_to_start(t_lem_in *lem_in, t_route_tree *tree)
{
	t_route_tree	*res;

	res = tree;
	while (res->room->prev->type != start)
	{
		res = route_tree_create_child(lem_in, res, res->room->prev);
	}
	res->skip = res->room->distance - 1;
	return (res);
}

/*
**	Iterates over current level node connections.
**	Stores the new list of node's connections.
**	Returns the bft information of the found path.
*/

static t_route		*extend_node(t_lem_in *lem_in, t_route_tree *node, t_glist **next_nodes)
{
	t_glist			*curr;
	t_route_tree	*new_node;
	static int		debug_pass;

	debug_pass++;
	if (lem_in->opt.debug)
	{
		ft_fprintf(2, "\nPass #%d\n", debug_pass);
		ft_fprintf(2, "Extending from:\t");
		// ft_fprintf(2, "\nExtending from:\t");
		route_tree_print(node);
	}
	// Viens d'entrer sur une route -> Remonter jusqu'a start.
	if (node->intersection != NULL && node->intersection == node->room)
	{
		new_node = go_to_start(lem_in, node);
		ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
		return (NULL);
	}
	node->room->visited = true;
	curr = node->room->links;
	while (curr != NULL)
	{
		if (can_go_to(node, curr->room))
		{
			new_node = route_tree_create_child(lem_in, node, curr->room);
			if (in_intersection(node->room, curr->room))
				new_node->intersection = curr->room;
			else if (out_intersection(node->room, curr->room))
				new_node->intersection = NULL;
			else if (curr->room->type == end)
			{
				if (lem_in->opt.debug)
				{
					ft_fprintf(2, "Found:\t\t");
					route_tree_print(node);
				}
				return (route_tree_to_route(new_node));
			}
			if (lem_in->opt.debug)
			{
				ft_fprintf(2, "Extending to:\t");
				route_tree_print(new_node);
			}
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
		}
		curr = curr->next;
	}
	route_tree_del(lem_in, node);
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
	ft_glstadd(&nodes, ft_glstnew(tree, sizeof(t_route_tree)));
	next_nodes = NULL;
	while (1)
	{
		res = extend_nodes_list(lem_in, nodes, &next_nodes);
		if (res != NULL)
			return (res);
		if (next_nodes == NULL)
			return (NULL);
		ft_glstdel(&nodes, NULL);
		if (res != NULL)
		{
			ft_glstdel(&next_nodes, NULL);
			return (res);
		}
		nodes = next_nodes;
		next_nodes = NULL;
	}
}
