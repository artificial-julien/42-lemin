/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:04:36 by juazouz           #+#    #+#             */
/*   Updated: 2019/03/07 15:05:00 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Saves the specified non comment line for display.
*/

void	save_display(t_lem_in *lem_in, char *line)
{
	t_list *new;

	new = NULL;
	if (line)
	{
		new = ft_lstnew(ft_strdup(line), 1);
		ft_lstadd(&lem_in->display, new);
	}
}

/*
**	Prints line of the list form the end to the start.
*/

void	print_display_line(t_list *display)
{
	while (display && display->content != NULL)
	{
		ft_printf("%s\n", display->content);
		display = display->next;
	}
}

/*
**	Print the lines of display.
*/

void	print_display(t_lem_in *lem_in)
{
	ft_lstrev(&lem_in->display);
	print_display_line(lem_in->display);
	ft_printf("\n");
}

/*
**	Free saved lines.
*/

void	free_saved_display(t_lem_in *lem_in)
{
	ft_lst_del(&lem_in->display);
}
