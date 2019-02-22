/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/21 18:06:28 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Saves the specified non comment line for display.
*/

void	save_line(t_lem_in *lem_in, char *line)
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

void	print_rec_line(t_list *display)
{
	if (display->content != NULL)
	{
		if (display->next == NULL)
			ft_printf("%s\n", display->content);
		else
		{
			print_rec_line(display->next);
			ft_printf("%s\n", display->content);
		}
	}
}

/*
**	Print the lines of display.
*/

void	print_lines(t_lem_in *lem_in)
{
	print_rec_line(lem_in->display);
	ft_printf("\n");
}

/*
**	Free saved lines.
*/

void	free_saved_line(t_lem_in *lem_in)
{
	ft_lst_del(&lem_in->display);
}
