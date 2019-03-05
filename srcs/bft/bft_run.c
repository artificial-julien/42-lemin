/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bft_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:35:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/05 16:24:44 by juazouz          ###   ########.fr       */
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
	intersection = NULL;
	if (in_intersection(node->room, dst))
	{
		augmentation--;
		if (augmentation < 0)
			return (NULL);
		intersection = node->intersection;
	}
	else if (out_intersection(node->room, dst))
		intersection = NULL;
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

	// Est sur end en suivant une route -> Remonter jusqu'a start.
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
	// Est sur end -> Trouvé ET augmentation > 0
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
		ft_fprintf(2, "Extending from (augmentations=%d):\t", node->augmentation);
		// ft_fprintf(2, "\nExtending from:\t");
		route_tree_print(node);
	}
	if (node && node->room->type == end)
	{
		if ((res = try_finalize_traverse(lem_in, node)) != NULL)
			return (res);
		new_node = traverse_end(lem_in, node);
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
	}
	// Marque la room si elle n'a pas de route.
	if (node->room->type == standard && node->room->next == NULL)
		node->room->visited = true;
	curr = node->room->links;
	while (curr != NULL)
	{
		new_node = traverse(lem_in, node, curr->room);
		// Ajoute le noeud créé pour le prochain niveau du parcours en largeur.
		if (new_node != NULL)
			ft_glstadd(next_nodes, ft_glstnew(new_node, sizeof(t_route_tree)));
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
		ft_fprintf(2, "Active branches : %d\n", ft_glstlen(next_nodes));
		ft_glstdel(&nodes, NULL);
		if (next_nodes == NULL)
			return (NULL);
		if (res != NULL)
		{
			ft_glstdel(&next_nodes, NULL);
			return (res);
		}
		nodes = next_nodes;
		next_nodes = NULL;
	}
}
