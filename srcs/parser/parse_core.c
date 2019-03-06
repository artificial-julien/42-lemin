/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/06 16:44:54 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function of parsing which read and test the number of ants
*/

void	parse_ants_count(t_lem_in *lem_in, char **line)
{
	int i;

	i = 0;
	if ((i = gnl_no_comm(0, line)) != -1)
	{
		if (ft_strlen(*line) <= MAX_NB_SIZE
			&& (i = parse_number_safe(*line)) > 0)
			lem_in->total_ants = i;
		else
		{
			ft_strdel(line);
			lem_in_die();
		}
		save_display(lem_in, *line);
		ft_strdel(line);
	}
	else
		lem_in_die();
}

/*
** Function which is parsing the line and create one rooms
*/

int		read_room_line(t_lem_in *lem_in, char **line, t_roomtype type)
{
	save_display(lem_in, *line);
	if (gnl_no_comm(0, line) == -1)
		lem_in_die();
	parse_room(lem_in, *line, type);
	return (1);
}

/*
**	Parses the rooms list. Stops on the first link line.
*/

void	parse_rooms(t_lem_in *lem_in, char **line)
{
	int		state;

	while ((state = gnl_no_comm(0, line)) != -1)
	{
		if (parse_is_link(*line))
		{
			break ;
		}
		if (ft_strnequ("##", *line, 2))
		{
			if (ft_strequ("##start", *line))
				read_room_line(lem_in, line, start);
			else if (ft_strequ("##end", *line))
				read_room_line(lem_in, line, end);
		}
		else
		{
			parse_room(lem_in, *line, standard);
		}
	}
	if (state == -1 || lem_in->start == NULL || lem_in->end == NULL)
		lem_in_die();
}

/*
**	Parses the list of links.
*/

void	parse_links(t_lem_in *lem_in, char **line)
{
	while (1)
	{
		if (!parse_is_link(*line))
		{
			ft_strdel(line);
			break ;
		}
		parse_link(lem_in, line);
		if (gnl_no_comm(0, line) == -1)
		{
			lem_in_die();
		}
	}
	ft_strdel(line);
	if (lem_in->start->links == 0 || lem_in->end->links_count == 0)
		lem_in_die();
}
