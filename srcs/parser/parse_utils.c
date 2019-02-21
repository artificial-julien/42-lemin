/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:10:58 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/21 16:35:54 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Parses the specified string to a number. Exit on error.
*/

int		parse_number(char *s)
{
	int	i;
	int	res;
	int	mul;

	i = 0;
	if (s[i] == '-')
	{
		mul = -1;
		i++;
	}
	else
		mul = 1;
	res = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			lem_in_die();
		res *= 10;
		res += '0' - s[i];
		if (res < 0)
			lem_in_die();
		i++;
	}
	return (res * mul);
}

/*
**	Returns true if the specified string contains room connection information.
*/

t_bool	parse_is_link(char *line)
{
	int	pos;
	int	len;

	len = ft_strlen(line);
	if (len < 3)
		return (false);
	pos = ft_strindex(line, '-');
	if (pos == -1 || pos < 1 || pos >= len - 1)
		return (false);
	return (true);
}

/*
**	Parses and cut the line in 3 part: the name, the coordinate x and y.
**	after that, he create a room for the list of room
**	Returns true if the specified string contains room information.
*/

void	parse_room(t_lem_in *lem_in, char *line, t_roomtype type)
{
	int		x;
	int		y;
	char	**tab;
	t_room	*new;

	if (((tab = ft_strsplit(line, ' ')) == NULL)
		|| tab[0] == NULL || tab[1] == NULL
		|| tab[2] == NULL || tab[3] != NULL
		|| (ft_strncmp(tab[0], "L", 1) == true)
		|| (ft_strlen(tab[1]) > MAX_NB_SIZE)
		|| (ft_strlen(tab[2]) > MAX_NB_SIZE)
		|| (room_find_name(lem_in, tab[0])) == 1)
	{
		ft_free_tab(&tab);
		lem_in_die();
	}
	x = parse_number(tab[1]);
	y = parse_number(tab[2]);
	new = room_new(tab[0], type, x, y);
	lem_in_add_room(lem_in, new);
	ft_free_tab(&tab);
	save_line(lem_in, line);
}

void	parse_link(t_lem_in *lem_in, char *line)
{
	char	*s1;
	char	*s2;
	int		pos;

	pos = ft_strindex(line, '-');
	s1 = ft_strsub(line, 0, pos);
	s2 = ft_strsub(line, pos + 1, ft_strlen(line) - pos);
	room_add_link(lem_in, s1, s2);
	room_add_link(lem_in, s2, s1);
	free(s1);
	free(s2);
	save_line(lem_in, line);
}
