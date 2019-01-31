/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:33:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/30 20:03:37 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Function testing the links for if the next room is empty
*/

t_bool		ants_can_move(t_list *links)
{
	t_room *r;

	r = links->content;
	if ((r->ants == 0 && r->type == standard) || (r->type == end))
		return (1);
	return (0);
}

/*
** function 
*/

int	trace_ways(t_lem_in *lem_in, t_room *r, t_list **way)
{
	int sum_way;
	t_room *tmp;
	int trace;
	char *name;

	sum_way = 0;
	if (r->type == end)
	{
		return (0);
		ft_lstadd(way,ft_lstnew(r->name, 1));
	}
	if (r->ants != 0)
	{
		if (r->links != NULL)
		{
			while ((tmp = r->links->content) != NULL)
			{
				trace = trace_ways(lem_in, tmp ,way);
				if (sum_way == 0)
				{
					sum_way = trace;
					name = tmp->name;
				}
				else if (sum_way > trace)
				{
						sum_way = trace;
						*way = ft_lst_del_one(*way, name, ft_strlen(name));
						name = tmp->name;
				}
				else
				{
					*way = ft_lst_del_one(*way, tmp->name, ft_strlen(tmp->name));
				}
				r->links = r->links->next;
			}
			ft_lstadd(way,ft_lstnew(name, ft_strlen(name)));
		}
	}
	return (sum_way);

}
/*
** Function of resolution of the programme
*/

void	solve(t_lem_in *lem_in, t_solution *solution)
{
	ft_printf("test solve\n");
	return ;
	while (lem_in->end->ants != lem_in->total_ants)
	{
		solution_add_round(solution);
		
	}
}
