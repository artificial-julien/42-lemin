/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/01 16:27:04 by juazouz          ###   ########.fr       */
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
	if (dst->visited)
	{
		return (false);
	}
	// On ne remonte pas la route existante.
	if (tree->room->prev != NULL && tree->room->prev == dst)
	{
		return (false);
	}
	// On ne repasse pas par le point d'intersection de la route actuellement coupée.
	if (tree->intersection == dst)
	{
		return (false);
	}
	// On ne resort pas aussitot de la route sur laquelle on vient d'entrer car on creerait une route croisée.
	if (tree->intersection != NULL
		&& tree->room == tree->intersection
		&& dst != tree->room->next)
	{
		return (false);
	}
	// On part de start en prenant une route existante (on evite de la suivre jusqu'a la fin)
	if (tree->room->type == start && dst->prev == tree->room)
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
	// Si on est sur une route et on la suit.
	if (src->next != NULL && src->next == dst)
		return (false);
	// Si dst n'a pas de route.
	if (dst->prev == NULL)
		return (false);
	// Si on est sur une route et on la suit. (encore?)
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
	res = route_tree_create_child(lem_in, tree, lem_in->start);
	res = route_tree_create_child(lem_in, res, room);
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
	if (node->room->type == end)
	{
		// Est sur end en suivant une route -> Remonter jusqu'a start.
		if (node->parent->room->next != NULL)
		{
			new_node = go_to_start(lem_in, node);
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
			if (lem_in->opt.debug)
			{
				ft_fprintf(2, "Extending to (from start):\t");
				route_tree_print(new_node);
			}
			return (NULL);
		}
		// Est sur end -> Trouvé ET augmentation > 0
		else if (new_node->augmentation > 0)
		{
			if (lem_in->opt.debug)
			{
				ft_fprintf(2, "Found:\t\t");
				route_tree_print(node);
			}
			return (route_tree_to_route(node));
		}
		else
		{
			route_tree_del(lem_in, node);
			return (NULL);
		}
	}
	// Marque la room si elle n'a pas de route.
	if (node->room->next == NULL)
		node->room->visited = true;
	curr = node->room->links;
	while (curr != NULL)
	{
		if (can_go_to(node, curr->room))
		{
			new_node = route_tree_create_child(lem_in, node, curr->room);
			if (in_intersection(node->room, curr->room))
			{
				new_node->augmentation--;
				new_node->intersection = curr->room;
			}
			else if (out_intersection(node->room, curr->room))
				new_node->intersection = NULL;
			if (lem_in->opt.debug)
			{
				ft_fprintf(2, "Extending to:\t");
				route_tree_print(new_node);
			}
			// Ajoute le noeud créé pour le prochaine niveau du parcours en largeur.
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
		}
		curr = curr->next;
	}
	// Efface le noeud et ses parents SEULEMENT SI ceux-ci n'ont plus d'enfants.
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
	
	// Création du noeud initial.
	nodes = NULL;
	tree = route_tree_new(lem_in);
	tree->room = lem_in->start;
	tree->augmentation = 1;
	ft_glstadd(&nodes, ft_glstnew(tree, sizeof(t_route_tree)));
	next_nodes = NULL;
	while (1)
	{
		// On avance au niveau suivant.
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
