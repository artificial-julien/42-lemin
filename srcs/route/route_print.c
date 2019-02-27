/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/27 15:30:59 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Prints the specified route.
**	Debug purposes.
*/

void		route_print(t_route *route)
{
	ft_fprintf(2, "Route #%2d (len=%3d)\t", route->id_route, route->len);
	print_nodes(route->rooms);
}
