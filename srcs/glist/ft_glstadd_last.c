/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:24:14 by agoulas           #+#    #+#             */
/*   Updated: 2019/01/28 15:14:33 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstadd_last(t_list **alst, t_list *n)
{
	t_list *cur;

	if (alst && n)
	{
		if (*alst == NULL)
		{
			(*alst) = n;
			(*alst)->next = NULL;
		}
		else if ((*alst)->content == NULL)
		{
			free(*alst);
			*alst = n;
			(*alst)->next = NULL;
		}
		else
		{
			cur = *alst;
			while (cur->next != NULL)
				cur = cur->next;
			cur->next = n;
		}
	}
}
