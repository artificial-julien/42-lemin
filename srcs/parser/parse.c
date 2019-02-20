/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:41:07 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/20 15:42:32 by juazouz          ###   ########.fr       */
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
	lem_in->nb_lem_algo = min_lem_in(lem_in);
	lem_in->start->ants = lem_in->total_ants;
	if (lem_in->opt.print_room == true || lem_in->opt.debug == true)
		lem_in_print_all_rooms(lem_in);
	parse_optimizer(lem_in);
	if (lem_in->opt.print_room == true || lem_in->opt.debug == true)
		lem_in_print_all_rooms(lem_in);
	ft_strdel(&line);
}
