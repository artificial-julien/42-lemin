/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bft_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:56:50 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 20:06:02 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*traverse(t_lem_in *lem_in, t_tree *node, t_room *dst)
{
	t_tree	*res;
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
	return (res);
}

t_tree	*traverse_end(t_lem_in *lem_in, t_tree *node)
{
	t_tree	*res;

	if (node->parent->room->next != NULL)
	{
		res = go_to_start(lem_in, node);
		return (res);
	}
	return (NULL);
}

t_route		*try_finalize_traverse(t_lem_in *lem_in, t_tree *node)
{
	(void)lem_in;
	if (node->augmentation > 0)
	{
		return (route_tree_to_route(node));
	}
	return (NULL);
}

/*
**	Iterates over current level node connections.
**	Stores the new list of node's connections.
**	Returns the found path if any.
*/

t_route		*extend_node(t_lem_in *lem_in, t_tree *node,
	t_glist **next_nodes)
{
	t_glist			*curr;
	t_tree	*new_node;
	t_route			*res;

	new_node = NULL;
	if (node->room->type == standard && node->room->next == NULL)
		node->room->visited = true;
	if (node && node->room->type == end)
	{
		if ((res = try_finalize_traverse(lem_in, node)) != NULL)
			return (res);
		new_node = traverse_end(lem_in, node);
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_tree)));
		return (NULL);
	}
	curr = node->room->links;
	while (curr != NULL)
	{
		new_node = traverse(lem_in, node, curr->gen.room);
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_tree)));
		curr = curr->next;
	}
	return (NULL);
}

/*
**	Iterates over current level nodes.
**	Stores a list of the next level nodes.
**	Returns the tree leaf of the first found path if any.
*/

t_route		*extend_nodes_list(t_lem_in *lem_in,
	t_glist *nodes, t_glist **next_nodes)
{
	t_glist		*curr;
	t_route		*res;

	curr = nodes;
	while (curr != NULL)
	{
		if ((res = extend_node(lem_in, curr->gen.tree, next_nodes)))
			return (res);
		curr = curr->next;
	}
	return (NULL);
}
