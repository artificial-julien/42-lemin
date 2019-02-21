/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/21 14:53:44 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	return the minum between the number of links of startroom ,
**	the numbers links of endroom and the numbers finals  of ants .
*/

int		min_lem_in(t_lem_in *lem)
{
	int res;
	int start;
	int end;

	res = 0;
	if (lem->start == NULL || lem->end == NULL)
		lem_in_die();
	start = lem->start->links_count;
	end = lem->end->links_count;
	res = (start < end) ? start : end;
	if (res < lem->total_ants)
		res = lem->total_ants;
	return (res);
}

/*
** Fonction to free a tab of char of 2 dimension
*/

void	ft_free_tab(char ***tab)
{
	int i;

	i = 0;
	if (*tab == NULL)
		return ;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

/*
**	Return the index of position from the start
**	of an charactere in the string or return -1
**	if it can t find the cractere in the string
*/

int		ft_strindex(const char *hay, char c)
{
	int i;

	i = 0;
	while (hay && hay[i] != '\0')
	{
		if (hay[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
**	Reads to the next non-comment line
**	Comments starts by "#"
**	"##" are NOT comments
*/

int		gnl_no_comm(const int fd, char **line)
{
	int	res;

	ft_strdel(line);
	while ((res = get_next_line(fd, line)) >= 0
			&& ft_strnequ("#", *line, 1)
			&& !(ft_strequ("##start", *line))
			&& !(ft_strequ("##end", *line)))
	{
		ft_strdel(line);
	}
	if (res == -1)
		return (-1);
	return (res);
}

/*
**	Prints the specified route.
**	Debug purposes.
*/

void	print_nodes(t_glist *nodes)
{
	t_glist	*curr;
	t_room	*room;
	char	*label;
	char	*padding;

	curr = nodes;
	while (curr != NULL)
	{
		room = curr->room;
		if (room->type == start)
			label = "[S]";
		else if (room->type == end)
			label = "[E]";
		else
			label = "";
		if (curr->next != NULL)
			padding = " - ";
		else
			padding = "";
		ft_fprintf(2, "(%s)%s%s", room->name, label, padding);
		curr = curr->next;
	}
	ft_fprintf(2, "\n");
}
