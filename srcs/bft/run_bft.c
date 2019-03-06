/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_bft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 20:04:29 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	============= breadth-first traversal execution =============
*/

/*
**	Resets the visited flags and the routes.
*/

static void			reset_visited(t_lem_in *lem_in)
{
	t_glist	*curr;

	curr = lem_in->rooms;
	while (curr != NULL)
	{
		curr->gen.room->visited = false;
		curr = curr->next;
	}
}

/*
**	Creates the initial single element list with the start node.
*/

static t_glist		*init_first_level(t_lem_in *lem_in)
{
	t_glist			*res;
	t_tree	*tree;

	res = NULL;
	tree = route_tree_new(lem_in);
	tree->room = lem_in->start;
	tree->augmentation = 1;
	ft_glstadd(&res, ft_glstnew(tree, sizeof(t_tree)));
	return (res);
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

	reset_visited(lem_in);
	nodes = init_first_level(lem_in);
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
