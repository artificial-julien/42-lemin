/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 19:56:45 by juazouz           #+#    #+#             */
/*   Updated: 2018/11/12 20:05:17 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*curr_in;
	t_list	**curr_out;

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
