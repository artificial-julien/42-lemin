/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 15:57:17 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 17:31:23 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_route_tree	*route_tree_new(t_lem_in *lem_in)
{
	t_route_tree	*res;

	(void)lem_in;
	res = ft_memalloc(sizeof(t_route_tree));
	return (res);
}

/*
**	Deletes the specified tree element ands its parents if there is no child.
*/

void			route_tree_del(t_lem_in *lem_in, t_route_tree *route_tree)
{
	t_route_tree	*del;
	t_route_tree	*curr;

	(void)lem_in;
	curr = route_tree;
	while (curr != NULL && curr->child_count == 0)
	{
		del = curr;
		if (curr->parent != NULL)
			curr->parent->child_count--;
		curr = curr->parent;
		free(del);
	}
}

t_route_tree	*route_tree_create_child(t_lem_in *lem_in, t_route_tree *parent, t_room *room)
{
	t_route_tree	*res;

	(void)lem_in;
	res = route_tree_new(lem_in);
	res->parent = parent;
	res->intersection = parent->intersection;
	res->augmentation = parent->augmentation;
	res->room = room;
	if (parent != NULL)
		parent->child_count++;
	return (res);
}

t_route			*route_tree_to_route(t_route_tree *route_tree)
{
	t_route_tree	*curr;
	t_route			*res;

	res = route_new();
	curr = route_tree;
	while (curr != NULL)
	{
		route_add_node(res, curr->room);
		curr = curr->parent;
	}
	return (res);
}
