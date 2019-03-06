/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:41:07 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/05 19:20:37 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Main parsing function.
*/

void	parse(t_lem_in *lem_in)
{
	char *line;

	line = NULL;
	parse_ants_count(lem_in, &line);
	parse_rooms(lem_in, &line);
	time_profiling(lem_in, false, "Room parsing");
	lem_in->array_room = (t_room**)glist_to_array(lem_in->rooms);
	array_sort((void **)lem_in->array_room, lem_in->room_count, room_cmp);
	time_profiling(lem_in, false, "List to array");
	parse_links(lem_in, &line);
	time_profiling(lem_in, false, "Links parsing");
	lem_in->start->ants = lem_in->total_ants;
	parse_optimizer(lem_in);
	time_profiling(lem_in, false, "Map optimization");
	ft_strdel(&line);
}
