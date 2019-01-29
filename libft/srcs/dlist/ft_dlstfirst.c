/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstfirst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:04:02 by juazouz           #+#    #+#             */
/*   Updated: 2019/01/29 15:10:25 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Runs throught the double linked list and returns the first element.
*/

t_dlist			*ft_dlstfirst(t_dlist *lst)
{
	t_dlist	*curr;

	curr = lst;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
