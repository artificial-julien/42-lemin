/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:39:09 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 16:24:16 by agoulas          ###   ########.fr       */
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
	t_glist	*new;

	new = ft_glstnew(room, sizeof(t_room));
	ft_glstadd(&lem_in->rooms, new);
}

/*
**	Free lem_in's elements.
*/

void	lem_in_free(t_lem_in *lem_in)
{
	ft_glstdel(&lem_in->rooms, room_free);
}

/*
**	Prints an error and terminates the program.
*/

void	lem_in_die(void)
{
	ft_putendl("ERROR");
	exit(EXIT_FAILURE);
}
