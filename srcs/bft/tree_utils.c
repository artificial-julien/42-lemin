/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:30:59 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 20:04:16 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			tree_del_list(t_lem_in *lem_in, t_glist **trees)
{
	while ((*trees) != NULL)
	{
		tree_del(lem_in, (*trees)->gen.tree);
		ft_glstdelone(trees, NULL);
	}
}

void			tree_print(t_tree *tree)
{
	if (tree->parent != NULL)
		tree_print(tree->parent);
	ft_fprintf(2, "BFT node [%-6s]\t(augmentation=%d, intersection=%s)\n",
		tree->room->name,
		tree->augmentation,
		tree->intersection != NULL ? tree->intersection->name : NULL);
}
