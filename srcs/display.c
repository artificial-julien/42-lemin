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
		ft_lstadd_last(&lem_in->data, new);
	}
}

/*
**	Prints all saved lines with save_line()
*/

void	print_lines(t_lem_in *lem_in)
{
	t_list *curr;

	curr = lem_in->data;
	while (curr != NULL && curr->content)
	{
		ft_printf("%s\n", curr->content);
		curr = curr->next;
	}
	ft_printf("\n");
}

/*
**	Free saved lines.
*/

void	free_saved_line(t_lem_in *lem_in)
{
	ft_lst_del(&lem_in->data);
}
