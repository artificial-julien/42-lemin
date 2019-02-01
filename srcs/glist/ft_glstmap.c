/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:56:45 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 16:47:48 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist	*ft_glstmap(t_glist *lst, t_glist *(*f)(t_glist *elem))
{
	t_glist	*begin;
	t_glist	*curr_in;
	t_glist	**curr_out;

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
