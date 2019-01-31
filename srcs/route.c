/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 18:54:42 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/31 14:49:11 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		route_cmp_conflit(t_route *route_a, t_route *route_b)
{
	t_list	*lst_a;
	t_list	*lst_b;
	t_room	*room_a;
	t_room	*room_b;

	lst_a = route_a->rooms;
	lst_b = route_b->rooms;
	while (lst_a && lst_a->content)
	{
		room_a = lst_a->content;
		while (room_a && lst_b && lst_b->content)
		{
			room_b = lst_b->content;
			if (room_a->name == room_b->name
				&& room_a->type == standard
				&& room_b->type == standard)
				return (1);
			lst_b = lst_b->next;
		}
		lst_a = lst_a->next;
	}
	return (0);
}
