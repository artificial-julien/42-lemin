/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:57:17 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 20:06:01 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tree	*tree_new(t_lem_in *lem_in)
{
	t_tree	*res;
	static int		id;

	(void)lem_in;
	res = ft_memalloc(sizeof(t_tree));
	id++;
	return (res);
}

/*
**	Deletes the specified tree element ands its parents if there is no child.
*/

void			tree_del(t_lem_in *lem_in, t_tree *tree)
{
	t_tree	*del;
	t_tree	*curr;

	(void)lem_in;
	curr = tree;
	while (curr != NULL && curr->child_count == 0)
	{
		del = curr;
		if (curr->parent != NULL)
			curr->parent->child_count--;
		curr = curr->parent;
		free(del);
	}
}

t_tree	*tree_create_child(t_lem_in *lem_in, t_tree *parent, t_room *room)
{
	t_tree	*res;

	(void)lem_in;
	res = tree_new(lem_in);
	res->parent = parent;
	res->intersection = parent->intersection;
	res->augmentation = parent->augmentation;
	res->room = room;
	if (parent != NULL)
		parent->child_count++;
	return (res);
}

t_route			*tree_to_route(t_tree *tree)
{
	t_tree	*curr;
	t_route			*res;

	res = route_new();
	curr = tree;
	while (curr != NULL)
	{
		route_add_node(res, curr->room);
		curr = curr->parent;
	}
	return (res);
}
