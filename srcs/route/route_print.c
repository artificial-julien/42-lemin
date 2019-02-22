/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:51:20 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/22 02:44:00 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Prints the specified route.
**	Debug purposes.
*/

void		route_print(t_route *route)
{
	ft_fprintf(2, "Route #%d\t", route->id_route);
	print_nodes(route->rooms);
}
