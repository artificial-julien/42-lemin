/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:54:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/31 13:07:55 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int  route_cmp_conflit(t_route *route_a, t_route *route_b)
{
	t_room *room_a;
	t_room *room_b;

	while(route_a && route_a->content->rooms)
	{
		room_a = route_a->content->rooms;
		while (room_a && route_b && route_b->content->rooms)
		{
			room_b = route_b->content->rooms;
			if (p->name == q->name
					&& q->type == standard && p->type == standard)
				return (1);
			route_b = route_b->next;
		}
		route_a = route_a->next;
	}
	return (0);
}
