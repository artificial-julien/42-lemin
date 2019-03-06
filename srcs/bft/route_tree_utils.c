/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_tree_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:30:59 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/06 17:31:26 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			route_tree_del_list(t_lem_in *lem_in, t_glist **trees)
{
	while ((*trees) != NULL)
	{
		route_tree_del(lem_in, (*trees)->tree);
		ft_glstdelone(trees, NULL);
	}
}

void			route_tree_print(t_route_tree *route_tree)
{
	t_route		*route;

	route = route_tree_to_route(route_tree);
	route_print(route);
	route_free(route, sizeof(t_route));
}
