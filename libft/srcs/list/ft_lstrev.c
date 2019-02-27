/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoulas <agoulas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:41:27 by agoulas           #+#    #+#             */
/*   Updated: 2019/02/27 14:28:44 by agoulas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Reverses the specified list.
*/

void	ft_lstrev(t_list **list)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

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
