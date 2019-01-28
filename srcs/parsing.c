/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 17:22:30 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse(t_lem_in *lem_in)
{
	char *line;

	line = NULL;
	parse_ants_count(lem_in, &line);
	parse_rooms(lem_in, &line);
	parse_links(lem_in, &line);
	ft_strdel(&line);
}

void	parse_ants_count(t_lem_in *lem_in, char **line)
{
	int i;

	i = 0;
	if ((i = get_next_line(0, line)) != -1)
	{
		if (ft_strlen(*line) <= 10 && (i = ft_atoi(*line)) > 0)
			lem_in->total_ants = i;
		else
			lem_in_die();
	}
}

int		parsing_room(t_lem_in *lem_in, char **line, t_roomtype type)
{
	int		i;
	int		x;
	int		y;
	t_room	*new;
	char	**tab;

	tab = NULL;
	i = 1;
	if ((i = get_next_line(0, line)) == -1)
		return (0);
	if ((tab = ft_strsplit(*line, ' ')) == NULL)
		return (0);
	if (ft_strlen(tab[1]) > 10 || ft_strlen(tab[2]) > 10)
		return (0);
	x = ft_atoi(tab[1]);
	y = ft_atoi(tab[2]);
	if ((new = room_new(tab[0], type, x, y)) == NULL)
		return (0);
	lem_in_add_room(lem_in, new);
	ft_free_tab(&tab);
	return (1);
}

void	parse_rooms(t_lem_in *lem_in, char **line)
{
	int i;
	char **tab;

	i = 1;
	tab = NULL;
	while(i != 0 && (i = get_next_line(0, line)) != -1 && line != NULL)
	{
		if (ft_strlen(*line) == 0 || ft_strindex(*line, '-') != -1)
			lem_in_die();
		else if (ft_strncmp("##", *line, 2) == 0)
		{
			if (ft_strncmp("##start", *line, 7) == 0)
				i = parsing_room(lem_in, line, start);
			else if (ft_strncmp("##end", *line, 5) == 0)
				i = parsing_room(lem_in, line, end);
		}
		else
			i = parsing_room(lem_in, line, standard);
	}
	if (*line == NULL || i == 0)
		lem_in_die();
}

void	parse_links(t_lem_in *lem_in, char **line)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 1;
	while (i != 0 && (i = get_next_line(0, line)) != -1 && line != NULL)
	{
		if (ft_strncmp("##", *line, 2) != 0)
		{
			if ((i = ft_strindex(*line, '-')) != -1)
				lem_in_die();
			else
			{
				s1 = ft_strsub(*line, 0, i);
				s2 = ft_strsub(*line, i + 1, ft_strlen(*line) - i);

				free(s1);
				free(s2);
			}
		}
	}
}
