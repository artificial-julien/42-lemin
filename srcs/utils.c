/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:59:35 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/05 13:22:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
**	Function which return the index of position from the start
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
**»·Function which return the index of position from the last
**»·of an charactere in the string or return -1
**»·if it can t find the cractere in the string
*/

int		ft_strrindex(const char *hay, char c)
{
	int i;

	i = ft_strlen(hay);
	while (i >= 0)
	{
		if (hay[i] == c)
			return (i);
		i--;
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
			&& !ft_strnequ("##", *line, 2))
	{
		ft_strdel(line);
	}
	return (res);
}

/*
**	Function testing the links for if the next room is empty
*/

t_bool	ants_cam_move(t_glist *links)
{
	t_room *r;

	r = *((t_room**)links->content);
	if ((r->ants == 0 && r->type == standard) || (r->type == end))
		return (1);
	return (0);
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
		ft_printf("(%s)%s%s", room->name, label, padding);
		curr = curr->next;
	}
	ft_putendl("");
}
