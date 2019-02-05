/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glsthascontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:49:05 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/05 12:51:08 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Returns true if the specified pointer is present in
**	one of the node's content.
*/

t_bool	ft_glsthascontent(t_glist *lst, void *content)
{
	t_glist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->content == content)
			return (true);
		curr = curr->next;
	}
	return (false);
}
