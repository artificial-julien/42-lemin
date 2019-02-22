/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:41:07 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/22 14:06:59 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function for parsing the input and create the information for the progams
*/

void	parse(t_lem_in *lem_in)
{
	char *line;

	line = NULL;
	parse_ants_count(lem_in, &line);
	parse_rooms(lem_in, &line);
	parse_links(lem_in, &line);
	time_profiling(lem_in, false, "Parsing");
	lem_in->start->ants = lem_in->total_ants;
	parse_optimizer(lem_in);
	time_profiling(lem_in, false, "Map optimization");
	ft_strdel(&line);
}
