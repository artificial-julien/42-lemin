/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:30:59 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 19:36:19 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			route_tree_del_list(t_lem_in *lem_in, t_glist **trees)
{
	while ((*trees) != NULL)
	{
		route_tree_del(lem_in, (*trees)->gen.tree);
		ft_glstdelone(trees, NULL);
	}
}

void			route_tree_print(t_route_tree *tree)
{
	if (tree->parent != NULL)
		route_tree_print(tree->parent);
	ft_fprintf(2, "BFT node [%-6s]\t(augmentation=%d, intersection=%s)\n",
		tree->room->name,
		tree->augmentation,
		tree->intersection != NULL ? tree->intersection->name : NULL);
}
