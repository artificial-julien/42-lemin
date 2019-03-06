/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/06 19:39:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Prints the specified route.
**	Debug purposes.
*/

void		route_print(t_route *route)
{
	t_bool	rev;

	rev = route->rooms->gen.room->type == end;
	ft_fprintf(2, "Route #%d (len=%d)\t", route->id_route, route->len);
	if (rev)
		ft_glstrev(&route->rooms);
	print_nodes(route->rooms);
	if (rev)
		ft_glstrev(&route->rooms);
}
