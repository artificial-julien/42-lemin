/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:55:08 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 13:51:38 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem))
{
	t_dlist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		f(curr);
		curr = curr->next;
	}
}
