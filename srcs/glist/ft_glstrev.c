/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:47:28 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/19 15:49:08 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Reverses the specified list.
*/

void	ft_glstrev(t_glist **list)
{
	t_glist	*curr;
	t_glist	*prev;
	t_glist	*next;

	curr = *list;
	prev = 0;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*list = prev;
}
