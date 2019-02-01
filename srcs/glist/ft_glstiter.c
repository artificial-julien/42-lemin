/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:55:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/01 16:47:40 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_glstiter(t_glist *lst, void (*f)(t_glist *elem))
{
	t_glist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		f(curr);
		curr = curr->next;
	}
}
