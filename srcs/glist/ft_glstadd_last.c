/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstadd_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 13:24:14 by agoulas           #+#    #+#             */
/*   Updated: 2019/03/06 19:36:52 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	ft_glstadd_last(t_glist **alst, t_glist *n)
{
	t_glist *cur;

	if (alst && n)
	{
		if (*alst == NULL)
		{
			(*alst) = n;
			(*alst)->next = NULL;
		}
		else if ((*alst)->gen.content == NULL)
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
