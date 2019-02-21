/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_data(t_lem_in *lem_in, char *line)
{
	t_list *new;

	new = NULL;
	if (line)
	{
		new = ft_lstnew(ft_strdup(line),1);
		ft_lstadd_last(&lem_in->data,new);
	}
}


void	print_data(t_lem_in *lem_in)
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
