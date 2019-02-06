/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_glstlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juazouz <juazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:47:13 by juazouz           #+#    #+#             */
/*   Updated: 2019/02/06 17:51:32 by juazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_glstlen(t_glist *list)
{
	t_glist	*curr;
	int		i;

	i = 0;
	curr = list;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}
