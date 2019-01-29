/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:56:45 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 13:51:38 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem))
{
	t_dlist	*begin;
	t_dlist	*curr_in;
	t_dlist	**curr_out;

	curr_out = &begin;
	curr_in = lst;
	while (curr_in != NULL)
	{
		*curr_out = f(curr_in);
		curr_out = &(*curr_out)->next;
		curr_in = curr_in->next;
	}
	return (begin);
}
