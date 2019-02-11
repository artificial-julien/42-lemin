/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_best_group.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:29:50 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/11 17:33:36 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_group		*select_best_group(t_glist *groups, int total_ants)
{
	t_group	*best;
	int		best_result;
	t_glist	*curr;
	int		curr_result;

	best = NULL;
	curr_result = 0;
	best_result = 0;
	curr = groups;
	while (curr != NULL)
	{
		curr_result = group_total_rounds(curr->group, total_ants);
		if (curr_result < best_result || best == NULL)
		{
			best_result = curr_result;
			best = curr->group;
		}
		curr = curr->next;
	}
	return (best);
}
