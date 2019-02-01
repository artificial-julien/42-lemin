/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_nodes_weights.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:28:06 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 11:45:29 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Iterates over current node connections.
**	Returns the list of node's connections.
**	Fills the current level with the specified weigth when appropriate.
*/

static void		extend_node(t_room *node, t_glist **new_list, int weight)
{
	t_glist	*curr;
	t_glist	*new_node;

	curr = node->links;
	while (curr != NULL)
	{
		if ((curr->room->type == standard)
			&& (curr->room->weigth == -1 || curr->room->weigth > weight))
		{
			new_node = ft_glstnew(curr->room, sizeof(t_room));
			ft_glstadd(new_list, new_node);
			new_node->room->weigth = weight;
#if DEBUG
			ft_fprintf(STDERR_FILENO,
						"Node\t\"%s\"\tweight = %d\n",
						new_node->room->name,
						new_node->room->weigth);
#endif
		}
		curr = curr->next;
	}
}

/*
**	Iterates over current level nodes.
**	Returns a list of the next level nodes.
*/

static t_glist	*extend_nodes_list(t_glist *nodes, int weight)
{
	t_glist	*curr;
	t_glist	*new_list;

	new_list = NULL;
	curr = nodes;
	while (curr != NULL)
	{
		extend_node(curr->room, &new_list, weight);
		curr = curr->next;
	}
	return (new_list);
}

/*
**	Fills the graph with weigths using breadth-first traversal.
**	Weigths are the distance to the end.
*/

void			create_nodes_weights(t_lem_in *lem_in)
{
	t_glist	*start;
	t_glist	*nodes;
	t_glist	*next_nodes;
	int		weight;

	nodes = NULL;
	start = ft_glstnew(lem_in->end, sizeof(t_room));
	ft_glstadd(&nodes, start);
	next_nodes = NULL;
	weight = 1;
	while ((next_nodes = extend_nodes_list(nodes, weight)) != NULL)
	{
		ft_glstdel(&nodes, NULL);
		nodes = next_nodes;
		weight++;
	}
}
