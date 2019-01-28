/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:39:09 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/28 16:52:50 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Initializes lem_in.
*/

void	lem_in_init(t_lem_in *lem_in)
{
	ft_bzero(lem_in, sizeof(t_lem_in));
}

/*
**	Records a new room.
*/

void	lem_in_add_room(t_lem_in *lem_in, t_room *room)
{
	t_list	*new;

	new = ft_lstnew(room, sizeof(t_room));
	ft_lstadd(&lem_in->rooms, new);
}

/*
**	Free lem_in's elements.
*/

void	lem_in_free(t_lem_in *lem_in)
{
	ft_lstdel(&lem_in->rooms, room_free);
}

/*
**	Prints an error and terminates the program.
*/

void	lem_in_die()
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}
